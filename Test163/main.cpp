#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isEndOfWord;
	string definition;

	TrieNode() : isEndOfWord(false){}
};

class Dictionary {
private:
	TrieNode* root;
	vector<string> history;
	vector<string> favouriteList;
	string dataSetPath;

	void insert(TrieNode* node, const string& word, const string& definition, int index) {
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

	TrieNode* search(TrieNode* node, const string& word, int index) {
		if (index == word.size()) {
			return node;
		}

		char c = word[index];
		if (!node->children[c]) {
			return nullptr;
		}
		return search(node->children[c], word, index + 1);
	}
	void deleteNode(TrieNode*& node) {
		if (!node) return;
		for (auto& child : node->children) {
			deleteNode(child.second);
		}
		delete node;
		node = nullptr;
	}

	void resetTrie() {
		deleteNode(root);
		root = new TrieNode();
	}

	void appendToFile(const string& word, const string& definition) {
		ofstream outfile(dataSetPath, ios::app);
		if (dataSetPath == "slang.txt") {
			outfile << word << "`" << definition << endl;
		}
		else if (dataSetPath == "emotional.txt.TXT") {
			outfile << word << "\t" << definition << endl;
		}
		outfile.close();
	}

	void searchByDefinition(TrieNode* node, const string& definition, string currentWord, vector<string>& results) {
		if (node->isEndOfWord && node->definition.find(definition) != string::npos) {
			results.push_back(currentWord);
		}

		for (auto& child : node->children) {
			searchByDefinition(child.second, definition, currentWord + child.first, results);
		}
	}
public:
	Dictionary(const string& path) : dataSetPath(path) {
		root = new TrieNode();
	}
	~Dictionary() {
		deleteNode(root);
	}

	void insert(const string& word, const string& definition) {
		insert(root, word, definition, 0);
		appendToFile(word, definition);
	}

	void loadDataSet() {
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
		}
		infile.close();
	}

	string search(const string& word) {
		TrieNode* node = search(root, word, 0);
		if (node && node->isEndOfWord) {
			history.push_back(word);
			return node->definition;
		}
		return "Word not found";
	}

	vector<string> searchByDefinition(const string& definition) {
		vector<string> results;
		searchByDefinition(root, definition, "", results);
		return results;
	}

	vector<string> viewHistory() const {
		return history;
	}

	void resetDictionary() {
		resetTrie();
	}
};

int main() {
	Dictionary dict1("slang.txt");
	Dictionary dict2("emotional.txt.TXT");

	dict1.loadDataSet();
	dict2.loadDataSet();

	// Example usage
	cout << dict1.search("BFF") << endl;
	cout << dict1.search(":-)") << endl;

	// Example usage
	cout << dict2.search("(-:") << endl;
	cout << dict2.search("2MFM") << endl;

	// Adding a new word and definition
	//dict1.insert("newSlang", "This is a new slang definition");
	//dict2.insert("newEmotion", "This is a new emotional definition");

	// Example usage
	cout << dict1.search("newSlang") << endl;
	cout << dict2.search("newEmotion") << endl;

	// Searching by definition
	vector<string> results = dict1.searchByDefinition("new slang");
	for (const string& word : results) {
		cout << "Found word: " << word << endl;
	}

	// Viewing search history
	vector<string> history = dict1.viewHistory();
	cout << "Search History:" << endl;
	for (const string& word : history) {
		cout << word << endl;
	}

	return 0;
}