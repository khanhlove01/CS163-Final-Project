#include "function.h"

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

void Dictionary::deleteNode(TrieNode*& node) {
    if (!node) return;
    for (auto& child : node->children) {
        deleteNode(child.second);
    }
    delete node;
    node = nullptr;
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
