#ifndef FUNCTION_H
#define FUNCTION_H

#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include <iostream>


#include <QListWidget>
#include <QString>
using namespace std;

void displayVectorInListWidget(QListWidget* listWidget, const vector<string>& vec);

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

    TrieNode* search(TrieNode* node, const string& word, int index);
    void insert(TrieNode* node, const string& word, const string& definition, int index);
    void appendToFile(const string& word, const string& definition);
    void saveHistoryToFile();
    void loadHistoryFromFile();
    void saveFavouritesToFile();
    void loadFavouritesFromFile();
    void updateFile(const string& word, const string& newDefinition);
    void deleteNode(TrieNode*& node);
    void searchByDefinition(TrieNode* node, const string& definition, string currentWord, vector<string>& results);

public:
    Dictionary(const string& path, const string& historyPath, const string& favouritePath);
    ~Dictionary();

    void insert(const string& word, const string& definition);
    void loadDataSet();
    string search(const string& word);
    vector<string> searchByDefinition(const string& definition);
    vector<string> viewHistory() const;
    bool editDefinition(const string& word, const string& newDefinition);



};

#endif // FUNCTION_H
