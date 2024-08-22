#ifndef FUNCTION_H
#define FUNCTION_H

#include "custom_map.h" 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct TrieNode {
    CustomUnorderedMap<char, TrieNode*> children;  
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
    vector<pair<string, string>> words;

    void insert(TrieNode* node, const string& word, const string& definition, int index);
    TrieNode* search(TrieNode* node, const string& word, int index);
    void deleteNode(TrieNode*& node);
    void resetTrie();
    void appendToFile(const string& word, const string& definition);
    void saveHistoryToFile();
    void loadHistoryFromFile();
    void saveFavouritesToFile();
    void loadFavouritesFromFile();
    void searchByDefinition(TrieNode* node, const string& definition, string currentWord, vector<string>& results);
    void updateFile(const string& word, const string& newDefinition);
    bool Isremoved(TrieNode*& node, const string& word, int index);
    void removeFromFile(const string& word);
    void writeDataSetToFile(const string& originalFilePath);

public:
    Dictionary(const string& path, const string& historyPath, const string& favouritePath);
    ~Dictionary();

    void insert(const string& word, const string& definition);
    void loadDataSet();
    string search(const string& word);
    vector<string> searchByDefinition(const string& definition);
    vector<string> viewHistory() const;
    void resetDictionary();
    void editDefinition(const string& word, const string& newDefinition);
    void addFavourite(const string& word);
    void removeFavourite(const string& word);
    vector<string> viewFavourites() const;
    void removeWordFromDictionary(const string& word);
    void resetToOriginal(const string& originalFilePath);
    pair<string, string> getRandomWord() const;
    tuple<string, vector<string>, int> getRandomWordWithDefinitions() const;
    tuple<string, vector<string>, int> getRandomDefinitionWithKeywords() const;
    bool wordExists(const string& word);

    string getDatasetPath();
};

#endif
