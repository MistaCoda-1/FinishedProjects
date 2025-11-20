#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------//
// Represents a library member
class Member {
private:
    string name;

public:
    void setUsername() {
        cout << "Member name: ";
        cin >> name;
        cout << "----------------------------------------------|\n";
        cout << "Welcome, [" << name << "]!\n";
        cout << "You enter the library, and approach a bookshelf . . .\n";
    }

    string getName() const {
        return name;
    }
};

//-----------------------------------------//
// Represents a single book
class Book {
private:
    string title;
    string author;
    bool borrowed;
    string borrowerName;

public:
    Book() {
        title = "Untitled";
        author = "Unknown";
        borrowed = false;
        borrowerName = "";
    }

    Book(string t, string a) {
        title = t;
        author = a;
        borrowed = false;
        borrowerName = "";
    }

    void display(int index) const {
        cout << index + 1 << " - " << title << " by " << author;
        if (borrowed)
            cout << " [BORROWED by " << borrowerName << "]";
        cout << endl;
    }

    bool isBorrowed() const {
        return borrowed;
    }

    void borrow(const string &memberName) {
        borrowed = true;
        borrowerName = memberName;
    }

    void returnBook() {
        borrowed = false;
        borrowerName = "";
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getBorrower() const {
        return borrowerName;
    }
};

//-----------------------------------------//
// Represents the library system
class Library {
private:
    Book books[5] = {
        Book("The Catcher in the Rye", "J.D. Salinger"),
        Book("1984", "George Orwell"),
        Book("To Kill a Mockingbird", "Harper Lee"),
        Book("The Alchemist", "Paulo Coelho"),
        Book("The Martian", "Andy Weir")
    };

public:
    void showBooks() const {
        cout << "----------------------------------------------|\n";
        for (int i = 0; i < 5; i++) {
            books[i].display(i);
        }
        cout << "----------------------------------------------|\n";
    }

    bool borrowBook(Member &member, int bookChoice) {
        if (bookChoice < 1 || bookChoice > 5) {
            cout << "ERROR! Invalid book choice!\n";
            return false;
        }

        Book &chosenBook = books[bookChoice - 1];
        if (chosenBook.isBorrowed()) {
            cout << "Sorry, " << chosenBook.getBorrower()
                 << " already borrowed that book.\n";
            return false;
        }

        chosenBook.borrow(member.getName());

        cout << "----------------------------------------------|\n";
        cout << "Borrow successful!\n";
        cout << "Member: " << member.getName() << endl;
        cout << "Book: " << chosenBook.getTitle()
             << " by " << chosenBook.getAuthor() << endl;
        cout << "----------------------------------------------|\n";
        return true;
    }

    bool returnBook(Member &member, int bookChoice) {
        if (bookChoice < 1 || bookChoice > 5) {
            cout << "ERROR! Invalid book choice!\n";
            return false;
        }

        Book &chosenBook = books[bookChoice - 1];
        if (!chosenBook.isBorrowed()) {
            cout << "That book wasn’t borrowed yet.\n";
            return false;
        }

        if (chosenBook.getBorrower() != member.getName()) {
            cout << "You can't return that book — "
                 << "it’s borrowed by " << chosenBook.getBorrower() << "!\n";
            return false;
        }

        chosenBook.returnBook();
        cout << "----------------------------------------------|\n";
        cout << "Book returned successfully!\n";
        cout << "----------------------------------------------|\n";
        return true;
    }
};

//-----------------------------------------//
int main() {
    Library lib;
    Member member;

    char retry;
    int choice;
    int bookChoice;

    cout << "== Library Simulator ==\n\n";

    member.setUsername();

    do {
        lib.showBooks();
        cout << "[1] Borrow a Book | [2] Return a Book: ";
        cin >> choice;

        cout << "Choose a book (1–5): ";
        cin >> bookChoice;

        if (choice == 1)
            lib.borrowBook(member, bookChoice);
        else if (choice == 2)
            lib.returnBook(member, bookChoice);
        else
            cout << "ERROR! Invalid input!\n";

        cout << "\nGo again? (y/n): ";
        cin >> retry;
        cout << endl;

    } while (retry == 'y' || retry == 'Y');

    cout << "\n-- Program Exited. --\n";
    return 0;
}
