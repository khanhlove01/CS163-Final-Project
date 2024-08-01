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

void Dictionary::insert(TrieNode* node, const string& word, const string& definition, int index) {
    if (index == word.size()) {
        node->isEndOfWord = true;
        node->definition = definition;
        return;
    }

    char c = word[index];
    if (!node->children[c]) {
        node->children[c] = new TrieNode();
    }
    insert(node->children[c], word, definition, index + 1);
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

void Dictionary::searchByDefinition(TrieNode* node, const string& definition, string currentWord, vector<string>& results) {
    if (node->isEndOfWord && node->definition.find(definition) != string::npos) {
        results.push_back(currentWord);
    }

    for (auto& child : node->children) {
        searchByDefinition(child.second, definition, currentWord + child.first, results);
    }
}

TrieNode* Dictionary::search(TrieNode* node, const string& word, int index) {
    if (index == word.size()) {
        return node;
    }

    char c = word[index];
    if (!node->children[c]) {
        return nullptr;
    }
    return search(node->children[c], word, index + 1);
}

string Dictionary::search(const string& word) {

    history.push_back(word);
    // return word;
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

