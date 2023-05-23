#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isLetterPresent(const std::string& secretWord, char letter) {
    for (char c : secretWord) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

void updateWord(const std::string& secretWord, std::string& guessedWord, char letter) {
    for (int i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == letter) {
            guessedWord[i] = letter;
        }
    }
}

int main() {
    std::vector<std::string> words = {"list", "of", "words"};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string secretWord = words[std::rand() % words.size()];
    std::string guessedWord(secretWord.length(), '_');

    int attempts = 6;
    std::vector<char> guessedLetters;

    while (attempts > 0) {
        std::cout << "Secret word: " << guessedWord << std::endl;
        std::cout << "Attempts remaining: " << attempts << std::endl;
        std::cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;

        char guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        std::cin.ignore();

        if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            std::cout << "You already guessed that letter!" << std::endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (isLetterPresent(secretWord, guess)) {
            updateWord(secretWord, guessedWord, guess);

            if (guessedWord == secretWord) {
                std::cout << "Congratulations! You guessed the word: " << secretWord << std::endl;
                break;
            }
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            --attempts;


            if (attempts == 0) {
                std::cout << "Game over! The word was: " << secretWord << std::endl;
            }
        }
    }

    return 0;
}
