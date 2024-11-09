#include <iostream>
#include <string>
#include <ctime>
#include<fstream>
using namespace std;
string generate() {
    srand(time(0));
    int count = rand() % 8+1;
    int k = 0;
    string a;
    string b;
    ifstream file("word.txt");

    while (getline(file, a)) {
        k++;
        if (k == count) {
            b = a;

        }
    }
    return b;
    file.close();
}
int main() {
    cout << "You have five attempts to guess the word" << endl;
    string wordToGuess = generate();
    string guessedWord(wordToGuess.length(), '_');
    int attempts = 5;



    cout << "the word consists of " << wordToGuess.length() << " letter" << endl;

    time_t startTime = time(0);
    while (attempts > 0) {
        cout << "the word consists of: " << guessedWord << endl;
        cout << "There are still attempts left: " << attempts << endl;
        cout << "enter the letter: ";
        char letter;
        cin >> letter;

        bool found = false;
        for (int i = 0; i < wordToGuess.length(); i++) {
            if (wordToGuess[i] == letter) {
                guessedWord[i] = letter;
                found = true;
            }
        }

        if (!found) {
            attempts--;
        }

        if (guessedWord == wordToGuess) {
            cout << "Congratulations, you guessed the word " << wordToGuess << endl;
            break;
        }
    }

    time_t endTime = time(0);
    double elapsedTime = difftime(endTime, startTime);
    cout << "Time: " << elapsedTime << " seconds" << endl;

    if (attempts == 0) {
        cout << "You've lost, the hidden word: " << wordToGuess << endl;
    }

    return 0;
}
