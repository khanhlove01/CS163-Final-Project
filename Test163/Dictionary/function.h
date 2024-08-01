#ifndef FUNCTION_H
#define FUNCTION_H

#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

    void insert(TrieNode* node, const string& word, const string& definition, int index);
    void appendToFile(const string& word, const string& definition);
    void saveHistoryToFile();
    void loadHistoryFromFile();
    void saveFavouritesToFile();
    void loadFavouritesFromFile();
    void deleteNode(TrieNode*& node);

public:
    Dictionary(const string& path, const string& historyPath, const string& favouritePath);
    ~Dictionary();

    void insert(const string& word, const string& definition);
    void loadDataSet();


};

#endif // FUNCTION_H
