#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse, std::sort, and std::transform
#include <random>    // For std::default_random_engine and std::shuffle
#include <cctype>    // For the toupper and tolower functions used by std::transform
#include <chrono>    // Used to seed the random number generator

// Using the standard namespace to simplify code, but in larger projects,
// it's often better to use std:: prefix for clarity.
using namespace std;

// This function gets a word or phrase from the user.
// It uses cin.ignore() to clear the input buffer, which is a common fix
// for problems with mixing cin >> and getline().
string GetWord(void) {
    string localString;
    cout << "\n\nPlease enter a word/phrase: ";
    // This line clears any leftover newline characters from the input buffer.
    cin.ignore();
    getline(cin, localString);
    cout << "You have entered: " << localString << " as your current word/phrase" << endl << endl;
    return localString;
}

// This function reverses a string using the modern std::reverse algorithm.
// It is more efficient and easier to read than a manual loop.
string ReverseWord(string originalString) {
    // The string is passed by value, so we are modifying a copy.
    // Creating a new string to be explicit about the result.
    string reversedString = originalString;
    reverse(reversedString.begin(), reversedString.end());
    cout << "Your word after reversing is: " << reversedString << endl << endl;
    return reversedString;
}

// This function converts a string to uppercase.
// It uses std::transform, which is the standard way to apply a function
// to every character in a range.
string ToUpper(string originalString) {
    transform(originalString.begin(), originalString.end(), originalString.begin(), ::toupper);
    cout << "Your word after converting into uppercase: " << originalString << endl;
    return originalString;
}

// This function converts a string to lowercase using the same modern approach.
string ToLower(string originalString) {
    transform(originalString.begin(), originalString.end(), originalString.begin(), ::tolower);
    cout << "Your word after converting into lowercase: " << originalString << endl;
    return originalString;
}

// This function randomizes the letters in a string using std::shuffle,
// which is the modern and correct replacement for std::random_shuffle.
// It seeds the random number generator using the system clock for better randomness.
string RandomiseWord(string originalString) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(originalString.begin(), originalString.end(), default_random_engine(seed));
    cout << "Your word after randomise: " << originalString << endl;
    return originalString;
}

// This function sorts the letters in a string alphabetically.
// It uses the efficient std::sort algorithm.
string OrderWord(string originalString) {
    sort(originalString.begin(), originalString.end());
    cout << "Your word in order: " << originalString << endl;
    return originalString;
}

// Handles the "Quit" option. It confirms the user's choice before exiting.
void QuitNow(void) {
    string quit;
    cout << "\nAre you sure (Y/N)?: ";
    cin >> quit;
    if (quit == "Y" || quit == "y" || quit == "Yes") {
        cout << "\nThank you for choosing string Manipulation. " << endl << endl;
        exit(EXIT_SUCCESS);
    }
}

// The main menu function, which serves as the program's control loop.
void Menu(void) {
    string currentString = "012345";
    string modifiedString = ""; // Initialize to an empty string to avoid junk output
    char menuOption;

    do {
        cout << "C++ String Manipulation challenge" << endl << endl;
        cout << "\t1. Enter a word or phrase (Current word/phrase is: " << currentString << ")" << endl;
        cout << "\t2. Reverse the current word." << endl;
        cout << "\t3. Convert the current word to uppercase." << endl;
        cout << "\t4. Convert the current word to lowercase." << endl;
        cout << "\t5. Randomise the letters in the current word." << endl;
        cout << "\t6. Sort the letters in the current word in ascending alphabetic order." << endl;
        cout << "\t0. Quit the program." << endl << endl;
        cout << "\tThe last word/phrase returned was: " << modifiedString << endl;
        cout << "\nPlease enter a valid option(1-6 or 0 to quit): ";
        cin >> menuOption;

        switch (menuOption) {
            case '1':
                currentString = GetWord();
                break;
            case '2':
                modifiedString = ReverseWord(currentString);
                break;
            case '3':
                modifiedString = ToUpper(currentString);
                break;
            case '4':
                modifiedString = ToLower(currentString);
                break;
            case '5':
                modifiedString = RandomiseWord(currentString);
                break;
            case '6':
                modifiedString = OrderWord(currentString);
                break;
            case '0':
                QuitNow();
                break;
            default:
                cout << "\nUnfortunately, " << menuOption << " is not a valid option, please try again." << endl << endl;
                break;
        }
    } while (true);
}

// The entry point of the program.
int main() {
    Menu();
    return 0;
}
