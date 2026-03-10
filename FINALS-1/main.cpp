// Standard Library Templates
    #include<iostream>
    #include<fstream>
    #include<sstream>
    #include<vector>
// User-Defined Headers
    #include "Book.h"
    #include "Literature.h"
    #include "Magazine.h"
    #include "Library.h"
using namespace std;

// Helper function that takes user input and calls the correct function
void doAction(int a, Library& lib, bool& session) {
    cin.ignore(9999, '\n');
    switch (a) {
    case 1:
        lib.addBook();
        break;
    case 2:
        lib.removeBook();
        break;
    case 3:
        lib.showBooks();
        break;
    case 4:
        lib.borrowBook();
        break;
    case 5:
        lib.returnBook();
        break;
    case 6:
        cout << "Program Exiting . . .\n";
        session = false;
        break;
    default:
        cout << "INVALID ACTION!\n";
        break;
    }
}

int main() {
    cout << "== | Librarian Simulator | ==\n";
    bool inSession = true;
    Library lib;

    string filename = "savefile.txt";

    lib.loadFromFile(filename);

    do {
        int action;

        cout << "\n[1] Add a Book\n"
             << "[2] Remove a Book\n"
             << "[3] View all Books\n"
             << "[4] Borrow a Book\n"
             << "[5] Return a Book\n"
             << "[6] Exit\n\n";

        cout << "Choose action: ";
        cin >> action;

        doAction(action, lib, inSession);

    } while (inSession);

    cout << "\nAll Changes Saved!\n";

    lib.saveToFile(filename);

    return 0;
}