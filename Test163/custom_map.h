#ifndef CUSTOM_MAP_H
#define CUSTOM_MAP_H

#include <vector>
#include <list>
#include <functional>
#include <iterator>

template <typename Key, typename Value>
class CustomUnorderedMap {
public:
    CustomUnorderedMap(size_t bucket_count = 16) : buckets(bucket_count) {}

    Value& operator[](const Key& key) {
        size_t index = getBucketIndex(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        buckets[index].emplace_back(key, Value());
        return buckets[index].back().second;
    }

    bool contains(const Key& key) const {
        size_t index = getBucketIndex(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    void erase(const Key& key) {
        size_t index = getBucketIndex(key);
        buckets[index].remove_if([&key](const std::pair<Key, Value>& pair) {
            return pair.first == key;
            });
    }

    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear();
        }
    }

    bool empty() const {
        for (const auto& bucket : buckets) {
            if (!bucket.empty()) {
                return false;
            }
        }
        return true;
    }

    class Iterator {
    public:
        using BucketIterator = typename std::list<std::pair<Key, Value>>::iterator;
        using OuterIterator = typename std::vector<std::list<std::pair<Key, Value>>>::iterator;

        Iterator(OuterIterator outer_it, OuterIterator outer_end)
            : outer_it(outer_it), outer_end(outer_end) {
            if (outer_it != outer_end) {
                inner_it = outer_it->begin();
                advanceOuterIterator();
            }
        }

        std::pair<Key, Value>& operator*() {
            return *inner_it;
        }

        Iterator& operator++() {
            ++inner_it;
            advanceOuterIterator();
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return outer_it != other.outer_it || (outer_it != outer_end && inner_it != other.inner_it);
        }

    private:
        OuterIterator outer_it, outer_end;
        BucketIterator inner_it;

        void advanceOuterIterator() {
            while (outer_it != outer_end && inner_it == outer_it->end()) {
                ++outer_it;
                if (outer_it != outer_end) {
                    inner_it = outer_it->begin();
                }
            }
        }
    };

    Iterator begin() {
        auto outer_it = buckets.begin();
        while (outer_it != buckets.end() && outer_it->empty()) {
            ++outer_it;
        }
        return Iterator(outer_it, buckets.end());
    }

    Iterator end() {
        return Iterator(buckets.end(), buckets.end());
    }

private:
    std::vector<std::list<std::pair<Key, Value>>> buckets;

    size_t getBucketIndex(const Key& key) const {
        return std::hash<Key>()(key) % buckets.size();
    }
};

#endif // CUSTOM_MAP_H
