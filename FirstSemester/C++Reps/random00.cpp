#include <iostream>
#include <string>
using namespace std;

class Member {
private:

string name;

public:

void username(string &memberName) {
    cout << "Member name: ";
    cin >> memberName;
    cout << "----------------------------------------------|\n";
    name = memberName;
    cout << "Welcome, [" << name << "]!\n";
    cout << "You enter the library, and approach a bookshelf . . .\n";
}

};

class Books {
private:
string titles[5] = { "The Cathcer in the Ryer", "1984",
    "To Kill a Mocking bird", "The Alchemist", "The Martian" };

string authors[5] = { "J.D. Salinger", "George Owel",
    "Harper Lee", "Paulo Coelho", "Andy Weir" };

public:

void showBooks() {
    cout << "----------------------------------------------|\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " - " << titles[i] << " by " << authors[i] << endl;
    }
    cout << "----------------------------------------------|\n";
}

string getBookTitle(int book__ID) {
    return titles[book__ID - 1];
}

string getBookAuthor(int book__ID) {
    return authors[book__ID - 1];
}

};

class Library {
private:

Books books;

int borrowedBooks[5] = { 0 };
string borrower[5];

bool isBorrowed = 1;

public:

bool bookSelection(string name, int &x) {

    do {
        cout << "Choose from the selection: ";
        cin >> x;

        if (x < 1 || x > 5) {
            cout << "ERROR! Invalid Input!\n";
            books.showBooks();
        } else if (borrowedBooks[x - 1] == 1) {
            cout << "Sorry, " << borrower[x - 1] << " already borrowed that book.\n";
            cout << "----------------------------------------------|";
            return false;
        } else {
            string author = books.getBookAuthor(x);
            string title = books.getBookTitle(x);

            cout << "You selected [" << title << "] by [" << author << "]!\n";
            cout << "----------------------------------------------|\n";
            borrowedBooks[x - 1] = isBorrowed;
            borrower[x - 1] = name;
            return true;
        }
    } while (x < 1 || x > 5);
}

void borrowBook(string memberName, int book__ID) {

    cout << "== Borrow Receipt ==\n\n";
    cout << "Member: " << memberName << endl;
    cout << "Book Title: " << books.getBookTitle(book__ID) << endl;
    cout << "Book Author: " << books.getBookAuthor(book__ID) << endl;
    cout << "----------------------------------------------|";
}

void retryPrompt(char &retry) {
    cout << "\nBorrow another book?(y/n): ";
    cin >> retry;
}

};
int main() {

    Member member1;
    Books books;
    Library lib;

    int choice;
    string memberName;
    char retry;

    cout << "== Library Simulator ==\n\n";
    do {
        member1.username(memberName);
    
        books.showBooks();

        if (lib.bookSelection(memberName, choice)) {
            lib.borrowBook(memberName, choice);
            lib.retryPrompt(retry);
        } else {
            lib.retryPrompt(retry);
        }

    } while (retry == 'y' || retry == 'Y');
    
    cout << "\n-- Program Exited. --\n";

    return 0;
}