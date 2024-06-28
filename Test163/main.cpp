#include "function.h"
#include <iostream>

using namespace std;

int main() {
    Dictionary dict1("slang.txt", "slang_history.txt", "slang_favourites.txt");
    Dictionary dict2("emotional.txt.TXT", "emotional_history.txt", "emotional_favourites.txt");

    dict1.loadDataSet();
    dict2.loadDataSet();

    // Example usage: Get a random word and its definition
    auto randomWord1 = dict1.getRandomWord();
    cout << "Random slang word: " << randomWord1.first << " - " << randomWord1.second << endl;

    auto randomWord2 = dict2.getRandomWord();
    cout << "Random emotional word: " << randomWord2.first << " - " << randomWord2.second << endl;

    // Viewing favourite list
    /*vector<string> favourites = dict1.viewFavourites();
    cout << "Favourite List:" << endl;
    for (const string& word : favourites) {
        cout << word << endl;
    }*/

    // Example usage: Add a word to favourites
    /*dict1.addFavourite("BFF");
    favourites = dict1.viewFavourites();
    cout << "Favourite List:" << endl;
    for (const string& word : favourites) {
        cout << word << endl;
    }*/

    // Example usage: Remove a word from favourites
    /*dict1.removeFavourite("BFF");
    favourites = dict1.viewFavourites();
    cout << "Favourite List:" << endl;
    for (const string& word : favourites) {
        cout << word << endl;
    }*/

    // Example usage: Get a random word with four definitions and the correct index
    auto result = dict1.getRandomWordWithDefinitions();
    string word = get<0>(result);
    vector<string> definitions = get<1>(result);
    int correctIndex = get<2>(result);

    cout << "Guess the correct definition for: " << word << endl;
    for (int i = 0; i < definitions.size(); ++i) {
        cout << i + 1 << ": " << definitions[i] << endl;
    }

    cout << "The correct definition is at index: " << correctIndex + 1 << endl; // Correct index is 0-based, user sees 1-based

    // Example usage: Get a random definition with four keywords and the correct index
    /*auto resultOfKeywords = dict1.getRandomDefinitionWithKeywords();
    string definition = get<0>(resultOfKeywords);
    vector<string> keywords = get<1>(resultOfKeywords);
    int correctIndexOfRightKeywords = get<2>(resultOfKeywords);

    cout << "Guess the correct word for the definition: " << definition << endl;
    for (int i = 0; i < keywords.size(); ++i) {
        cout << i + 1 << ": " << keywords[i] << endl;
    }

    cout << "The correct word is at index: " << correctIndexOfRightKeywords + 1 << endl; 

    return 0;*/
}
