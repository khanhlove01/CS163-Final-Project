#include "function.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "===== Dictionary Menu =====" << endl;
    cout << "1. Switch Data Set" << endl;
    cout << "2. Search by Keyword" << endl;
    cout << "3. Search by Definition" << endl;
    cout << "4. View Search History" << endl;
    cout << "5. Add New Word and Definition" << endl;
    cout << "6. Edit Word Definition" << endl;
    cout << "7. Remove Word from Dictionary" << endl;
    cout << "8. Reset Dictionary to Original State" << endl;
    cout << "9. View Random Word and Definition" << endl;
    cout << "10. View Favourite List" << endl;
    cout << "11. Add/Remove Word from Favourite List" << endl;
    cout << "12. Guess the Correct Definition" << endl;
    cout << "13. Guess the Correct Word" << endl;
    cout << "0. Exit" << endl;
    cout << "===========================" << endl;
    cout << "Enter your choice: ";
}
// ==============================================================
// ==============================================================
// ==============================================================
// 1. Choose Dataset
void chooseDataSet(Dictionary*& dict, string& currentDataset) {
    cout << "Choose Data Set:" << endl;
    cout << "1. Slang" << endl;
    cout << "2. Emotional" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        delete dict;
        dict = new Dictionary("slang.txt", "slang_history.txt", "slang_favourites.txt");
        dict->loadDataSet();
        currentDataset = "slang";
        cout << "Switched to slang dataset." << endl;
        break;
    case 2:
        delete dict;
        dict = new Dictionary("emotional.txt.TXT", "emotional_history.txt", "emotional_favourites.txt");
        dict->loadDataSet();
        currentDataset = "emotional";
        cout << "Switched to emotional dataset." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        chooseDataSet(dict, currentDataset);
    }
}
// ==============================================================
// ==============================================================
// ==============================================================
// 2. Search By keyword
void searchByKeyword(Dictionary* dict) {
    cout << "Enter keyword to search: ";
    string keyword;
    cin >> keyword;
    cout << "Definition: " << dict->search(keyword) << endl;
}
// ==============================================================
// ==============================================================
// ==============================================================
// 3. Search by definition
void searchByDefinition(Dictionary* dict) {
    cout << "Enter definition to search: ";
    string definition;
    cin.ignore();
    getline(cin, definition);
    vector<string> results = dict->searchByDefinition(definition);
    if (results.empty()) {
        cout << "No words found with the given definition." << endl;
    }
    else {
        cout << "Words found: ";
        for (const string& word : results) {
            cout << word << " ";
        }
        cout << endl;
    }
}
// ==============================================================
// ==============================================================
// ==============================================================
// 4. View History
void viewHistory(Dictionary* dict) {
    vector<string> history = dict->viewHistory();
    if (history.empty()) {
        cout << "No search history available." << endl;
    }
    else {
        cout << "Search History: ";
        for (const string& word : history) {
            cout << word << " ";
        }
        cout << endl;
    }
}
// ==============================================================
// ==============================================================
// ==============================================================
// 5. Add new word
void addNewWord(Dictionary* dict) {
    cout << "Enter new word: ";
    string word;
    cin >> word;
    cout << "Enter definition: ";
    string definition;
    cin.ignore();
    getline(cin, definition);
    dict->insert(word, definition);
    cout << "New word added to the dictionary." << endl;
}
// ==============================================================
// ==============================================================
// ==============================================================
// 6. Edit Definition
void editDefinition(Dictionary* dict) {
    cout << "Enter word to edit: ";
    string word;
    cin >> word;
    cout << "Enter new definition: ";
    string newDefinition;
    cin.ignore();
    getline(cin, newDefinition);
    dict->editDefinition(word, newDefinition);
}
// ==============================================================
// ==============================================================
// ==============================================================
// 7. Remove word
void removeWord(Dictionary* dict) {
    cout << "Enter word to remove: ";
    string word;
    cin >> word;
    dict->removeWordFromDictionary(word);
}
int main() {
    string currentDataset = "slang";
    Dictionary* dict = new Dictionary("slang.txt", "slang_history.txt", "slang_favourites.txt");
    dict->loadDataSet();

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            chooseDataSet(dict, currentDataset);
            break;
        case 2:
            searchByKeyword(dict);
            break;
        case 3:
            searchByDefinition(dict);
            break;
        case 4:
            viewHistory(dict);
            break;
        case 5:
            addNewWord(dict);
            break;
        case 6:
            editDefinition(dict);
            break;
        case 7:
            removeWord(dict);
            break;
        case 8:
            //resetDictionary(dict, "originalslang.txt");
            break;
        case 9:
            //viewRandomWord(dict);
            break;
        case 10:
            //viewFavourites(dict);
            break;
        case 11:
            //manageFavourites(dict);
            break;
        case 12:
            //guessCorrectDefinition(dict);
            break;
        case 13:
            //guessCorrectWord(dict);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    delete dict;
    return 0;
}
