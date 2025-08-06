#include <iostream>
using namespace std;

int main() {

    char dog, cat;
    char choice;
    bool hasDog, hasCat;

    cout << "`||` || 'OR' Operator\n";
    cout << "Yes, I know it looks confusing lol\n" << endl;

    cout << "The `||` operator functions like this: " << endl;
    cout << "if (x > y || z < y) {'run code if AT LEAST ONE condition is met'}\n" << endl;

    cout << "In simpler terms, it checks if EITHER ONE of the two conditions are met, and runs the code." << endl;
    cout << "Try it yourself? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
    cout << "\nDo you have a dog? (y/n): ";
    cin >> dog;
    cout << "Do you have a cat? (y/n): ";
    cin >> cat;
    } else {
        cout << "\nYou don't want to learn..? :(";
        system("timeout /t 2 >nul");
        exit(0);
    }

    // I'm sure I don't have to explain this, but i'll do it anyway.
    // The code below checks if the user inputs 'y' or 'Y'
    // If that's true, it assigns `true` to `hasDog`
    // else, if the user enters anything besides `y` or `Y`
    // it assigns `false` to `hasDog`

    if (dog == 'y' || dog == 'Y') {
        hasDog = true; 
    } else {
        hasDog = false;
    }

    // same operation here as above

    if (cat == 'y' || cat == 'Y') {
        hasCat = true;
    } else {
        hasCat = false;
    }

    //=========
    // OUTPUT
    //=========

    if (hasDog || hasCat) {
        cout << "\nYou either have a dog, or a cat!";
    } else {
        cout << "\nYou have neither a dog nor cat :(";
    }

    return 0;
}