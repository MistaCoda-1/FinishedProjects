#include <iostream>
using namespace std;

int main() {

    int x, y;
    char choice, userLocation;
    bool livesInDasma;

    cout << "`!` || 'NOT' Operator\n";

    cout << "The `!` operator functions like this: " << endl;
    cout << "if (!x) {'run code'}\n" << endl;

    cout << "In simpler terms, it checks if x is NOT TRUE, and runs the code." << endl;
    cout << "Try it yourself? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "\nDo you live in Dasmarinas? (y/n): ";
        cin >> userLocation;
    } else {
        cout << "\nYou don't want to learn..? :(";
        system("timeout /t 2 >nul");
        exit(0);
    }

    if (userLocation == 'y' || userLocation == 'Y') {
        livesInDasma = true;
    } else {
        livesInDasma = false;
    }

    if (!livesInDasma) {
        cout << "You have to leave early for school!";
    } else {
        cout << "You live in Dasmarinas";
    }

    return 0;
}

// IGNORE THIS MESSAGE