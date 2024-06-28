#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <set>
#include <unordered_set>
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
	string historyFilePath;
	string favouriteFilePath;
	vector<pair<string, string>> words; // Vector to store words and their definitions

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

	void saveHistoryToFile() {
		ofstream outfile(historyFilePath);
		for (const auto& word : history) {
			outfile << word << endl;
		}
		outfile.close();
	}

	void loadHistoryFromFile() {
		ifstream infile(historyFilePath);
		string word;
		while (getline(infile, word)) {
			history.push_back(word);
		}
		infile.close();
	}

	void saveFavouritesToFile() {
		ofstream outfile(favouriteFilePath);
		for (const auto& word : favouriteList) {
			outfile << word << endl;
		}
		outfile.close();
	}

	void loadFavouritesFromFile() {
		ifstream infile(favouriteFilePath);
		string word;
		while (getline(infile, word)) {
			favouriteList.push_back(word);
		}
		infile.close();
	}

	void searchByDefinition(TrieNode* node, const string& definition, string currentWord, vector<string>& results) {
		if (node->isEndOfWord && node->definition.find(definition) != string::npos) {
			results.push_back(currentWord);
		}

		for (auto& child : node->children) {
			searchByDefinition(child.second, definition, currentWord + child.first, results);
		}
	}

	void updateFile(const string& word, const string& newDefinition) {
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

	// Implementation of remove function in TrieNode
	bool Isremoved(TrieNode*& node, const string& word, int index) {
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

	// Remove a word and its definition from the file
	void removeFromFile(const string& word) {
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

	

public:
	Dictionary(const string& path, const string& historyPath, const string& favouritePath)
		: dataSetPath(path), historyFilePath(historyPath), favouriteFilePath(favouritePath) {
		root = new TrieNode();
		loadHistoryFromFile();
		loadFavouritesFromFile();
		srand(time(0));
	}
	~Dictionary() {
		deleteNode(root);
		saveHistoryToFile();
		saveFavouritesToFile();
	}

	void insert(const string& word, const string& definition) {
		insert(root, word, definition, 0);
		appendToFile(word, definition);
		words.push_back({ word, definition });
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
			words.push_back({ word, definition });
		}
		infile.close();
	}

	string search(const string& word) {
		history.push_back(word);
		saveHistoryToFile();
		TrieNode* node = search(root, word, 0);
		if (node && node->isEndOfWord) {
			/*history.push_back(word);
			saveHistoryToFile();*/
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

	void editDefinition(const string& word, const string& newDefinition) {
		TrieNode* node = search(root, word, 0);
		if (node && node->isEndOfWord) {
			node->definition = newDefinition;
			updateFile(word, newDefinition);
		}
	}

	void addFavourite(const string& word) {
		if (find(favouriteList.begin(), favouriteList.end(), word) == favouriteList.end()) {
			favouriteList.push_back(word);
			saveFavouritesToFile();
		}
	}

	void removeFavourite(const string& word) {
		auto it = find(favouriteList.begin(), favouriteList.end(), word);
		if (it != favouriteList.end()) {
			favouriteList.erase(it);
			saveFavouritesToFile();
		}
	}

	vector<string> viewFavourites() const {
		return favouriteList;
	}

	void removeWordFromDictionary(const string& word) {
		if (Isremoved(root, word, 0)) {
			removeFromFile(word);
			auto it = remove_if(words.begin(), words.end(), [&](const pair<string, string>& p) { return p.first == word; });
			if (it != words.end()) {
				words.erase(it, words.end());
			}
		}
	}

	void writeDataSetToFile(const string& originalFilePath) {
		ifstream infile(originalFilePath);
		ofstream outfile(dataSetPath, ios::trunc);
		string line;

		while (getline(infile, line)) {
			outfile << line << endl;
		}

		infile.close();
		outfile.close();
	}

	void resetToOriginal(const string& originalFilePath) {
		resetTrie();  // Reset the Trie
		writeDataSetToFile(originalFilePath);  // Write original data to current dataset file
		loadDataSet();  // Load the data from the current dataset file into the Trie
	}

	pair<string, string> getRandomWord() const {
		if (words.empty()) {
			return { "", "No words available" };
		}
		int randomIndex = rand() % words.size();
		return words[randomIndex];
	}

	tuple<string, vector<string>, int> getRandomWordWithDefinitions() const {
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

		// Get the index of the correct definition before shuffling
		int correctDefinitionIndex = 0;

		// Shuffle the definitions and update the correct definition index
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
	//tuple<string, vector<string>, int> getRandomDefinitionWithKeywords() const {
	//	if (words.size() < 4) {
	//		return { "", {"Not enough words available"}, -1 };
	//	}

	//	int randomIndex = rand() % words.size();
	//	string correctWord = words[randomIndex].first;
	//	string correctDefinition = words[randomIndex].second;

	//	unordered_set<int> usedIndices = { randomIndex };
	//	vector<string> keywords = { correctWord };

	//	while (keywords.size() < 4) {
	//		int index;
	//		do {
	//			index = rand() % words.size();
	//		} while (usedIndices.find(index) != usedIndices.end());

	//		usedIndices.insert(index);
	//		keywords.push_back(words[index].first);
	//	}

	//	// Get the index of the correct keyword before shuffling
	//	int correctKeywordIndex = 0;

	//	// Shuffle the keywords and update the correct keyword index
	//	for (int i = keywords.size() - 1; i > 0; --i) {
	//		int j = rand() % (i + 1);
	//		swap(keywords[i], keywords[j]);
	//		if (i == correctKeywordIndex) {
	//			correctKeywordIndex = j;
	//		}
	//		else if (j == correctKeywordIndex) {
	//			correctKeywordIndex = i;
	//		}
	//	}

	//	return make_tuple(correctDefinition, keywords, correctKeywordIndex);
	//}


};

int main() {
	Dictionary dict1("slang.txt", "slang_history.txt", "slang_favourites.txt");
	Dictionary dict2("emotional.txt.TXT", "emotional_history.txt", "emotional_favourites.txt");

	dict1.loadDataSet();
	dict2.loadDataSet();
	//reset
	//dict1.resetToOriginal("originalslang.txt");
	//dict2.resetToOriginal("originalemotional.txt.TXT");

	// Example usage: Get a random word and its definition
	auto randomWord1 = dict1.getRandomWord();
	cout << "Random slang word: " << randomWord1.first << " - " << randomWord1.second << endl;

	auto randomWord2 = dict2.getRandomWord();
	cout << "Random emotional word: " << randomWord2.first << " - " << randomWord2.second << endl;
	// Viewing favourite list
	vector<string> favourites = dict1.viewFavourites();
	cout << "Favourite List:" << endl;
	for (const string& word : favourites) {
		cout << word << endl;
	}
	// Example usage: Add a word to favourites
	dict1.addFavourite("BFF");
	favourites = dict1.viewFavourites();
	cout << "Favourite List:" << endl;
	for (const string& word : favourites) {
		cout << word << endl;
	}
	// Example usage: Remove a word from favourites
	dict1.removeFavourite("BFF");
	favourites = dict1.viewFavourites();
	cout << "Favourite List:" << endl;
	for (const string& word : favourites) {
		cout << word << endl;
	}

	// Example usage: Get a random word with four definitions and the correct index
	auto result = dict1.getRandomWordWithDefinitions();
	string word = std::get<0>(result);
	vector<string> definitions = std::get<1>(result);
	int correctIndex = std::get<2>(result);

	cout << "Guess the correct definition for: " << word << endl;
	for (int i = 0; i < definitions.size(); ++i) {
		cout << i + 1 << ": " << definitions[i] << endl;
	}

	cout << "The correct definition is at index: " << correctIndex + 1 << endl; // Correct index is 0-based, user sees 1-based

	// Example usage: Get a random definition with four keywords and the correct index
	//auto resultOfKeywords = dict1.getRandomDefinitionWithKeywords();
	//string definition = std::get<0>(resultOfKeywords);
	//vector<string> keywords = std::get<1>(resultOfKeywords);
	//int correctIndexOfRightKeywords = std::get<2>(resultOfKeywords);

	//cout << "Guess the correct word for the definition: " << definition << endl;
	//for (int i = 0; i < keywords.size(); ++i) {
	//	cout << i + 1 << ": " << keywords[i] << endl;
	//}

	//cout << "The correct word is at index: " << correctIndexOfRightKeywords + 1 << endl; // Correct index is 0-based, user sees 1-based
	// Example usage
	//cout << dict1.search("BFF") << endl;
	//dict1.addFavourite("BFF");

	//cout << dict1.search(":-)") << endl;
	//dict1.addFavourite(":-)");

	// Example usage
	//cout << dict2.search("(-:") << endl;
	//dict2.addFavourite("(-:");

	//cout << dict2.search("2MFM") << endl;
	//dict2.addFavourite("2MFM");

	// Adding a new word and definition
	//dict1.insert("newSlang", "This is a new slang definition");
	//dict2.insert("newEmotion", "This is a new emotional definition");

	// Example usage
	//cout << dict1.search("newSlang") << endl;
	//cout << dict2.search("newEmotion") << endl;

	// Editing a word's definition
	//dict1.editDefinition("newSlang2", "This is an updated slang2 definition");
	//cout << dict1.search("newSlang2") << endl;
	// Searching by definition
	/*vector<string> results = dict1.searchByDefinition("new slang");
	for (const string& word : results) {
		cout << "Found word: " << word << endl;
	}*/

	// Viewing search history
	/*vector<string> history1 = dict1.viewHistory();
	cout << "Search History:" << endl;
	for (const string& word : history1) {
		cout << word << endl;
	}*/

	// Viewing search history
	/*vector<string> history2 = dict2.viewHistory();
	cout << "Search History:" << endl;
	for (const string& word : history2) {
		cout << word << endl;
	}*/

	// Viewing favourite list
	/*vector<string> favourites = dict1.viewFavourites();
	cout << "Favourite List:" << endl;
	for (const string& word : favourites) {
		cout << word << endl;
	}*/

	// Removing a word
	// Example usage: Remove a word
	//cout << dict1.search("newSlang2") << endl; // => This is an updated slang1 definition
	//dict1.removeWordFromDictionary("newSlang2");
	//cout << dict1.search("newSlang2") << endl; // => Not found

	//cout << dict2.search("2MFM") << endl; // => To much for me
	//dict2.removeWordFromDictionary("2MFM");
	//cout << dict2.search("2MFM") << endl; // => Not found

	return 0;
}