#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    // Set up game variables
    const int MAX_WRONG = 8; // maximum number of incorrect guesses allowed
    vector<string> words; // collection of possible words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; // word to guess
    int wrong = 0; // number of incorrect guesses
    string soFar(THE_WORD.size(), '-'); // word guessed so far
    string used = ""; // letters already guessed

    cout << "Welcome to Hangman. Good luck!" << endl;

    // Main game loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        // Display current status of game
        cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left."<<endl;
        cout << "You have used the following letters: " << used << endl;
        cout << "Word so far: "<<soFar<<endl;

        // Get user's guess
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess); // convert guess to uppercase

        while (used.find(guess) != string::npos) {
            cout << "You've already guessed " << guess << ". Enter a different letter: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos) {
            cout << "That's right! " << guess << " is in the word." << endl;
            for (int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        } else {
            cout << "Sorry, " << guess << " isn't in the word." << endl;
            ++wrong;
        }
    }

    // End of game
    if (wrong == MAX_WRONG) {
        cout << "\n\nYou've been hanged! The word was " << THE_WORD << "." << endl;
    } else {
        cout << "\n\nCongratulations! You guessed the word " << THE_WORD << "!" << endl;
    }

return 0;
}