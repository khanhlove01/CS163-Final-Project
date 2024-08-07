#include "function.h"
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

Dictionary::Dictionary(const string& path, const string& historyPath, const string& favouritePath)
    : dataSetPath(path), historyFilePath(historyPath), favouriteFilePath(favouritePath) {
    root = new TrieNode();
    loadHistoryFromFile();
    loadFavouritesFromFile();
    srand(time(0));
}

Dictionary::~Dictionary() {
    deleteNode(root);
    saveHistoryToFile();
    saveFavouritesToFile();
}

void Dictionary::insert(TrieNode* node, const string& word, const string& definition, int index) {
    if (index == word.size()) {
        node->isEndOfWord = true;
        node->definition = definition;
        return;
    }

    char c = word[index];
    if (!node->children.contains(c)) {
        node->children[c] = new TrieNode();
    }
    insert(node->children[c], word, definition, index + 1);
}

TrieNode* Dictionary::search(TrieNode* node, const string& word, int index) {
    if (index == word.size()) {
        return node;
    }

    char c = word[index];
    if (!node->children.contains(c)) {
        return nullptr;
    }
    return search(node->children[c], word, index + 1);
}

void Dictionary::deleteNode(TrieNode*& node) {
    if (!node) return;
    for (auto& child : node->children) {
        deleteNode(child.second);
    }
    delete node;
    node = nullptr;
}

void Dictionary::resetTrie() {
    deleteNode(root);
    root = new TrieNode();
}

void Dictionary::appendToFile(const string& word, const string& definition) {
    ofstream outfile(dataSetPath, ios::app);
    if (dataSetPath == "slang.txt") {
        outfile << word << "`" << definition << endl;
    }
    else if (dataSetPath == "emotional.txt.TXT") {
        outfile << word << "\t" << definition << endl;
    }
    outfile.close();
}

void Dictionary::saveHistoryToFile() {
    ofstream outfile(historyFilePath);
    for (const auto& word : history) {
        outfile << word << endl;
    }
    outfile.close();
}

void Dictionary::loadHistoryFromFile() {
    ifstream infile(historyFilePath);
    string word;
    while (getline(infile, word)) {
        history.push_back(word);
    }
    infile.close();
}

void Dictionary::saveFavouritesToFile() {
    ofstream outfile(favouriteFilePath);
    for (const auto& word : favouriteList) {
        outfile << word << endl;
    }
    outfile.close();
}

void Dictionary::loadFavouritesFromFile() {
    ifstream infile(favouriteFilePath);
    string word;
    while (getline(infile, word)) {
        favouriteList.push_back(word);
    }
    infile.close();
}

void Dictionary::searchByDefinition(TrieNode* node, const string& definition, string currentWord, vector<string>& results) {
    if (node != nullptr && node->definition.find(definition) != string::npos) {
        if (node->isEndOfWord) {
            results.push_back(currentWord);
        }
    }
    if (node != nullptr) {
        for (auto& child : node->children) {
            searchByDefinition(child.second, definition, currentWord + child.first, results);
        }
    }
}

void Dictionary::updateFile(const string& word, const string& newDefinition) {
    ifstream infile(dataSetPath);
    ofstream outfile("temp.txt");
    string line;

    while (getline(infile, line)) {
        istringstream iss(line);
        string existingWord, existingDefinition;
        if (dataSetPath == "slang.txt") {
            getline(iss, existingWord, '`');
        }
        else if (dataSetPath == "emotional.txt.TXT") {
            getline(iss, existingWord, '\t');
        }
        getline(iss, existingDefinition);

        if (existingWord == word) {
            existingDefinition = newDefinition;
        }

        if (dataSetPath == "slang.txt") {
            outfile << existingWord << "`" << existingDefinition << endl;
        }
        else if (dataSetPath == "emotional.txt.TXT") {
            outfile << existingWord << "\t" << existingDefinition << endl;
        }
    }

    infile.close();
    outfile.close();
    remove(dataSetPath.c_str());
    rename("temp.txt", dataSetPath.c_str());
}

bool Dictionary::Isremoved(TrieNode*& node, const string& word, int index) {
    if (!node) return false;

    if (index == word.size()) {
        if (!node->isEndOfWord) return false;
        node->isEndOfWord = false;
        return node->children.empty();
    }

    char c = word[index];
    if (!Isremoved(node->children[c], word, index + 1)) {
        return false;
    }

    delete node->children[c];
    node->children.erase(c);
    return !node->isEndOfWord && node->children.empty();
}

void Dictionary::removeFromFile(const string& word) {
    ifstream infile(dataSetPath);
    ofstream outfile("temp.txt");
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string existingWord, existingDefinition;
        if (dataSetPath == "slang.txt") {
            getline(iss, existingWord, '`');
        }
        else if (dataSetPath == "emotional.txt.TXT") {
            getline(iss, existingWord, '\t');
        }
        getline(iss, existingDefinition);

        if (existingWord != word) {
            if (dataSetPath == "slang.txt") {
                outfile << existingWord << "`" << existingDefinition << endl;
            }
            else if (dataSetPath == "emotional.txt.TXT") {
                outfile << existingWord << "\t" << existingDefinition << endl;
            }
        }
    }

    infile.close();
    outfile.close();
    remove(dataSetPath.c_str());
    rename("temp.txt", dataSetPath.c_str());
}

void Dictionary::writeDataSetToFile(const string& originalFilePath) {
    ifstream infile(originalFilePath);
    ofstream outfile(dataSetPath, ios::trunc);
    string line;

    while (getline(infile, line)) {
        outfile << line << endl;
    }

    infile.close();
    outfile.close();
}

string Dictionary::getDatasetPath()
{
    return this->dataSetPath;
}

void Dictionary::resetToOriginal(const string& originalFilePath) {
    resetTrie();
    writeDataSetToFile(originalFilePath);
    loadDataSet();
}

pair<string, string> Dictionary::getRandomWord() const {
    if (words.empty()) {
        return { "", "No words available" };
    }
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

tuple<string, vector<string>, int> Dictionary::getRandomWordWithDefinitions() const {
    if (words.size() < 4) {
        return { "", {"Not enough words available"}, -1 };
    }

    int randomIndex = rand() % words.size();
    string correctWord = words[randomIndex].first;
    string correctDefinition = words[randomIndex].second;

    unordered_set<int> usedIndices = { randomIndex };
    vector<string> definitions = { correctDefinition };

    while (definitions.size() < 4) {
        int index;
        do {
            index = rand() % words.size();
        } while (usedIndices.find(index) != usedIndices.end());

        usedIndices.insert(index);
        definitions.push_back(words[index].second);
    }

    int correctDefinitionIndex = 0;

    for (int i = definitions.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(definitions[i], definitions[j]);
        if (i == correctDefinitionIndex) {
            correctDefinitionIndex = j;
        }
        else if (j == correctDefinitionIndex) {
            correctDefinitionIndex = i;
        }
    }

    return make_tuple(correctWord, definitions, correctDefinitionIndex);
}

tuple<string, vector<string>, int> Dictionary::getRandomDefinitionWithKeywords() const {
    if (words.size() < 4) {
        return { "", {"Not enough words available"}, -1 };
    }

    int randomIndex = rand() % words.size();
    string correctWord = words[randomIndex].first;
    string correctDefinition = words[randomIndex].second;

    unordered_set<int> usedIndices = { randomIndex };
    vector<string> keywords = { correctWord };

    while (keywords.size() < 4) {
        int index;
        do {
            index = rand() % words.size();
        } while (usedIndices.find(index) != usedIndices.end());

        usedIndices.insert(index);
        keywords.push_back(words[index].first);
    }

    int correctKeywordIndex = 0;

    for (int i = keywords.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(keywords[i], keywords[j]);
        if (i == correctKeywordIndex) {
            correctKeywordIndex = j;
        }
        else if (j == correctKeywordIndex) {
            correctKeywordIndex = i;
        }
    }

    return make_tuple(correctDefinition, keywords, correctKeywordIndex);
}

void Dictionary::insert(const string& word, const string& definition) {
    insert(root, word, definition, 0);
    appendToFile(word, definition);
    words.push_back({ word, definition });
}

void Dictionary::loadDataSet() {
    ifstream infile(dataSetPath);
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string word, definition;
        if (dataSetPath == "slang.txt") {
            getline(iss, word, '`');
        }
        else if (dataSetPath == "emotional.txt.TXT") {
            getline(iss, word, '\t');
        }
        getline(iss, definition);
        insert(root, word, definition, 0);
        words.push_back({ word, definition });
    }
    infile.close();
}

string Dictionary::search(const string& word) {
    history.push_back(word);
    saveHistoryToFile();
    TrieNode* node = search(root, word, 0);
    if (node && node->isEndOfWord) {
        return node->definition;
    }
    return "Word not found";
}

vector<string> Dictionary::searchByDefinition(const string& definition) {
    vector<string> results;
    searchByDefinition(root, definition, "", results);
    return results;
}

vector<string> Dictionary::viewHistory() const {
    return history;
}

void Dictionary::resetDictionary() {
    resetTrie();
}

void Dictionary::editDefinition(const string& word, const string& newDefinition) {
    TrieNode* node = search(root, word, 0);
    if (node && node->isEndOfWord) {
        node->definition = newDefinition;
        updateFile(word, newDefinition);
    }
    else {
        cout << "Word not found in the dictionary." << endl;
    }
}

void Dictionary::addFavourite(const string& word) {
    if (find(favouriteList.begin(), favouriteList.end(), word) == favouriteList.end()) {
        favouriteList.push_back(word);
        saveFavouritesToFile();
    }
}

void Dictionary::removeFavourite(const string& word) {
    auto it = find(favouriteList.begin(), favouriteList.end(), word);
    if (it != favouriteList.end()) {
        favouriteList.erase(it);
        saveFavouritesToFile();
    }
}

vector<string> Dictionary::viewFavourites() const {
    return favouriteList;
}

void Dictionary::removeWordFromDictionary(const string& word) {
    if (!Isremoved(root, word, 0)) {
        removeFromFile(word);
        auto it = remove_if(words.begin(), words.end(), [&](const pair<string, string>& p) { return p.first == word; });
        if (it != words.end()) {
            words.erase(it, words.end());
        }
    }
}

bool Dictionary::wordExists(const string& word) {
    TrieNode* node = search(root, word, 0);
    return node && node->isEndOfWord;
}
