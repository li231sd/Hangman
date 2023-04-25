#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    //Game words
    string words[] = {
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry",
        "fig",
        "pesto",
        "rice",
        "sushi",
        "taco",
        "tofu",
        "pizza",
        "tea",
        "curry",
        "burger",
        "pasta",
        "grape",
        "honeydew",
        "kiwi",
        "lemon",
        "mango",
        "orange",
        "papaya",
        "peach",
        "pear",
        "pineapple",
        "plum",
        "raspberry",
        "strawberry",
        "watermelon"
    };

    //Initializing variables for the game
    string word;
    string correctChars;
    int lives = 6;
    int min = 0;
    int incorrectGuesses = 0;
    int max = sizeof(words) / sizeof(words[0]);
    char guess;
    bool found = false;
    bool incorrect = false;
    bool wordFound = false;

    //Finding a random word for the game
    srand(static_cast < unsigned int > (time(0)));
    int wordIndex = rand() % (max - min) + min;
    word = words[wordIndex];

    cout << "Welcome to Hangman (Food Edition) \n";

    //Main game loop
    while (lives != 0) {
        //Generating the _ _ _ for the game
        for (int i = 0; i < word.size(); i++) {
            if (correctChars.find(word[i]) != string::npos) {
                cout << word[i] << " ";
            } else {
                cout << "_ ";
            }
        }

        //Checking for correct and incorrect answer/telling user what they got
        if (found) {
            if (wordFound == false) {
                cout << "\nThe character was correct! \n";
                found = false;
            }
        } else if (incorrect) {
            if (wordFound == false) {
                cout << "\nThe character was incorrect! \n";
                lives--;
                cout << "Lives: " << lives << endl;
                incorrect = false;

                if (lives == 0) {
                    cout << "   _____\n";
                    cout << "  |     |\n";
                    cout << "  O     |\n";
                    cout << " /|\\    |\n";
                    cout << " / \\    |\n";
                    cout << "        |\n";
                    cout << "_________\n";
                    cout << "You lose! The word was: " << word << endl;
                    break;
                } else {
                    incorrectGuesses++;
                    switch (incorrectGuesses) {
                    case 1:
                        cout << "   _____\n";
                        cout << "  |     |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "_________\n";
                        break;
                    case 2:
                        cout << "   _____\n";
                        cout << "  |     |\n";
                        cout << "  O     |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "_________\n";
                        break;
                    case 3:
                        cout << "   _____\n";
                        cout << "  |     |\n";
                        cout << "  O     |\n";
                        cout << "  |     |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "_________\n";
                        break;
                    case 4:
                        cout << "   _____\n";
                        cout << "  |     |\n";
                        cout << "  O     |\n";
                        cout << " /|\\    |\n";
                        cout << "        |\n";
                        cout << "        |\n";
                        cout << "_________\n";
                        break;
                    case 5:
                        cout << "   _____\n";
                        cout << "  |     |\n";
                        cout << "  O     |\n";
                        cout << " /|\\    |\n";
                        cout << " /      |\n";
                        cout << "        |\n";
                        cout << "_________\n";
                        break;
                    case 6:
                        cout << "   _____\n";
                        cout << "  |     |\n";
                        cout << "  O     |\n";
                        cout << " /|\\    |\n";
                        cout << " / \\    |\n";
                        cout << "        |\n";
                        cout << "_________\n";
                        cout << "Game over! The word was: " << word << endl;
                        break;
                    }
                }
            }
        }

        //Win check
        else {
            if (wordFound) {
                cout << "You Win! \n";
            }
        }

        //User guess
        cout << "\nPlease guess a character: ";
        cin >> guess;

        for (int i = 0; i < word.size(); i++) {
            //Checking if the guess was correct
            if (word[i] == guess) {
                found = true;
                correctChars += guess;
                break;
            } else {
                incorrect = true;
            }
        }

        wordFound = true;

        for (int i = 0; i < word.size(); i++) {
            //Checking if we cannot make a word out of the correctChars
            if (correctChars.find(word[i]) == string::npos) {
                wordFound = false;
                break;
            }
        }

        //Checking if they have won
        if (wordFound) {
            cout << "You Win! The word was: " << word << endl;
            break;
        }
    }

    return 0;
}
