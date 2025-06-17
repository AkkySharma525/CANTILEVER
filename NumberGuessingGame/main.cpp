#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getTargetByLevel(char level) {
    if (level == 'E' || level == 'e') return rand() % 20 + 1;
    if (level == 'M' || level == 'm') return rand() % 40 + 1;
    return rand() % 60 + 1; // Default to Hard
}

void playGame() {
    srand(time(0));
    char level;
    int target, guess;
    const int maxAttempts = 5;

    cout << "=====================================\n";
    cout << " 🎮 WELCOME TO THE NUMBER GUESS GAME 🎯\n";
    cout << "=====================================\n";
    cout << "Choose Difficulty Level:\n";
    cout << "   E - Easy   (1 to 20)\n";
    cout << "   M - Medium (1 to 40)\n";
    cout << "   H - Hard   (1 to 60)\n";
    cout << "Enter your choice: ";
    cin >> level;

    target = getTargetByLevel(level);

    cout << "\nI've selected a number for you to guess.\n";
    cout << "You have " << maxAttempts << " attempts. Enter 0 to quit anytime.\n\n";

    for (int i = 0; i < maxAttempts; ++i) {
        cout << "Attempt " << i + 1 << ": Enter your guess: ";
        cin >> guess;

        if (guess == 0) {
            cout << "\nYou chose to quit. Goodbye!\n";
            return;
        }

        if (guess == target) {
            cout << "\n🎉 YOU WON!! You guessed the correct number!\n";
            cout << "Attempts used: " << i + 1 << "\n";
            cout << "============================\n";
            return;
        } else if (guess < target) {
            cout << "You selected a small number... Try a bigger one.\n";
        } else {
            cout << "You selected a large number... Try a smaller one.\n";
        }

        cout << (maxAttempts - i - 1) << " chances left.\n\n";
    }

    cout << "😢 OOPS! You Lost.\n";
    cout << "The correct number was: " << target << "\n";
    cout << "============================\n";
}

int main() {
    char playAgain;

    do {
        system("cls"); // For Windows: Clears screen (use "clear" if on Linux/Mac)
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! 🎮 See you again!\n";
    return 0;
}
