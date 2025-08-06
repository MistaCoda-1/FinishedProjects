#include <iostream>
using namespace std;

int main() {

    char dog, cat;
    char choice;
    bool hasDog, hasCat;

    cout << "`&&` || 'AND' Operator\n";

    cout << "The `&&` operator functions like this: " << endl;
    cout << "if (x > y && z < y) {'run code if BOTH conditions are met'}\n" << endl;

    cout << "In simpler terms, it checks if BOTH conditions are met, and runs the code." << endl;
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

    // This has the same explanation for the OR operator
    // Just check that, and you'll understand... hopefully

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

    if (hasDog && hasCat) {
        cout << "\nYou have a dog, and a cat! Yay! :D";
    } else if (hasDog || hasCat) {
        cout << "\nYou either have a dog, or a cat!";
    } else {
        cout << "\nYou don't have pets :(";
    }

    return 0;
}
