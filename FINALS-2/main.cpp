// Standard Template Libraries
    #include<iostream>
    #include<fstream>
    #include<vector>
// User-Defined Libraries
    #include "Book.h"
    #include "Literature.h"
    #include "Magazine.h"
    #include "Library.h"

void doAction(int a, Library& l, bool& session) { 
    cin.ignore(9999, '\n');
    switch (a) {
    case 1: l.showBooks(); break;
    case 2: l.addBook(); break;
    case 3: l.removeBook(); break;
    case 4: l.borrowBook(); break;
    case 5: l.returnBook(); break;
    case 6: cout << "\nProgram Exiting . . .\n"; session = false; break;
    default: cout << "\nINVALID ACTION!\n\n"; break;
    }
}

int main() {

    Library l;
    string filename = "savefile.txt";

    bool session = true;

    l.loadFromFile(filename);

    cout << "== Librarian Simulator ==\n";

    do {
        int action;

        cout << "[1] Show All Books\n"
                << "[2] Add Book\n"
                << "[3] Remove Book\n"
                << "[4] Borrow Book\n"
                << "[5] Return Book\n"
                << "[6] Exit\n\n";

        cout << "Enter Action: ";
        cin >> action;

        doAction(action, l, session);
    } while (session);

    l.saveToFile(filename);

    return 0;
}