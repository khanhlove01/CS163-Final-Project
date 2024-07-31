#ifndef FUNCTION_H
#define FUNCTION_H

#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    string definition;

    TrieNode() : isEndOfWord(false) {}
};

class Dictionary {
private:
    TrieNode* root;
    vector<string> history;
    vector<string> favouriteList;
    string dataSetPath;
    string historyFilePath;
    string favouriteFilePath;
    vector<pair<string, string>> words; // Vector to store words and their definitions

    void saveHistoryToFile();
    void loadHistoryFromFile();
    void saveFavouritesToFile();
    void loadFavouritesFromFile();
    void deleteNode(TrieNode*& node);

public:
    Dictionary(const string& path, const string& historyPath, const string& favouritePath);
    ~Dictionary();


};

#endif // FUNCTION_H
