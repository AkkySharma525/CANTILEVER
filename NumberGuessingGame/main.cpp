#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Function to generate a random target number based on the selected difficulty level
int getTargetByLevel(char level) {
    if (level == 'E' || level == 'e') return rand() % 20 + 1;  // Easy: 1–20
    if (level == 'M' || level == 'm') return rand() % 40 + 1;  // Medium: 1–40
    return rand() % 60 + 1;                                    // Hard: 1–60 (default)
}

// Main gameplay logic
void playGame() {
    srand(time(0));  // Seed the random number generator with current time

    char level;
    int target, guess;
    const int maxAttempts = 5;

    // Game introduction and difficulty selection
    cout << "=====================================\n";
    cout << " 🎮 WELCOME TO THE NUMBER GUESS GAME 🎯\n";
    cout << "=====================================\n";
    cout << "Choose Difficulty Level:\n";
    cout << "   E - Easy   (1 to 20)\n";
    cout << "   M - Medium (1 to 40)\n";
    cout << "   H - Hard   (1 to 60)\n";
    cout << "Enter your choice: ";
    cin >> level;

    // Validate and set difficulty level
    if (level == 'E' || level == 'e' || level == 'M' || level == 'm' || level == 'H' || level == 'h') {
        target = getTargetByLevel(level);  // Get the random target number
    } else {
        cout << "Error! Enter Valid Difficulty Level";
        return;
    }

    // Offer the user an optional hint
    char hintChoice;
    cout << "💡 Press 'T' if you want a hint before you start guessing else N: ";
    cin >> hintChoice;

    // Display hint if user chooses 'T' or 't'
    if (hintChoice == 'T' || hintChoice == 't') {
        cout << "\n🧠 _Hint_: “ Try guessing somewhere in the middle... then narrow it down like a pro.”\n";
        cout << "   (It's like cutting the range in half — over and over 😉)\n\n";
    }

    // Start guessing process
    cout << "\nI've selected a number for you to guess.\n";
    cout << "You have " << maxAttempts << " attempts. Enter 0 to quit anytime.\n\n";

    // Loop for 5 attempts
    for (int i = 0; i < maxAttempts; ++i) {
        cout << "Attempt " << i + 1 << ": Enter your guess: ";
        cin >> guess;

        if (guess == 0) {
            cout << "\nYou chose to quit. Goodbye!\n";
            return;
        }

        if (guess == target) {
            // User guessed correctly
            cout << "\n🎉 YOU WON!! You guessed the correct number!\n";
            cout << "Attempts used: " << i + 1 << "\n";
            cout << "============================\n";
            return;
        } else if (guess < target) {
            // Guess is too low
            cout << "You selected a small number... Try a bigger one.\n";
        } else {
            // Guess is too high
            cout << "You selected a large number... Try a smaller one.\n";
        }

        // Show remaining attempts
        cout << (maxAttempts - i - 1) << " chances left.\n\n";
    }

    // If user fails to guess within attempts
    cout << "😢 OOPS! You Lost.\n";
    cout << "The correct number was: " << target << "\n";
    cout << "============================\n";
}

// Main Function
int main() {
    char playAgain;

    do {
        system("cls");  // Clears the screen (Windows only)
        playGame();     // Start the game
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    // Exit message
    cout << "Thanks for playing! 🎮 See you again!\n";
    return 0;
}