#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int studentId;
    string studentName;

public:
    Student() : studentId(0), studentName("") {}
    Student(int id, string name) : studentId(id), studentName(name) {}

    int getId() const { return studentId; }
    string getName() const { return studentName; }

    void setName(const string &name) { studentName = name; }
    void setId(int id) { studentId = id; }

    void displayInfo() const {
        cout << "Student Name: " << studentName << "\n";
        cout << "Student ID: " << studentId << "\n";
    }
};

class Book {
private:
    string title;
    string author;
    int bookId;
    bool borrowState;
    int borrowerId;

    string category;
    string yearPublished;

public:
    Book() : title(""), author(""), bookId(0), borrowState(false), borrowerId(0),
             category(""), yearPublished("00/00/0000") {}

    Book(const string &t, const string &a, int id, const string &c, const string &year)
        : title(t), author(a), bookId(id), borrowState(false), borrowerId(0),
          category(c), yearPublished(year) {}

    void displayInfo() const {
        cout << title;
        if (borrowState) {
            cout << " [BORROWED BY " << borrowerId << "]";
        }
        cout << endl;
    }

    void borrow(int id) {
        if (borrowState) {
            cout << "This book is already borrowed!\n";
        } else {
            borrowState = true;
            borrowerId = id;
        }
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getBookId() const { return bookId; }
    bool isBorrowed() const { return borrowState; }
    int getBorrowerId() const { return borrowerId; }
    string getCategory() const { return category; }
    string getYearPublished() const { return yearPublished; }
};

class Library {
private:
    Book books[3] = {
        Book("The Man Who Moved", "Socrates", 321145, "History", "01/27/1003"),
        Book("The Man Who Couldn't Move", "Socrates", 2314, "History", "05/12/1004"),
        Book("The Man Who Moved It", "Socrates", 2145, "History", "09/03/1002")
    };
    int maxBooks = 3;

public:
    void displayBooks() const {
        for (int i = 0; i < maxBooks; i++) {
            cout << "[" << i + 1 << "] - ";
            books[i].displayInfo();
        }
    }

    void borrowBook(int studentId) {
        int bookChoice;

        cout << "Pick a book 1 - " << maxBooks << ": ";
        cin >> bookChoice;

        if (bookChoice < 1 || bookChoice > maxBooks) {
            cout << "Invalid book choice!\n";
            cin.clear();
            cin.ignore(9999, '\n');
            return;
        }

        Book &chosenBook = books[bookChoice - 1];
        cin.clear();
        cin.ignore(9999, '\n');

        cout << "\n+ - | BORROW RECEIPT | - +\n";
        cout << "Title: " << chosenBook.getTitle() << endl
             << "Author: " << chosenBook.getAuthor() << endl
             << "Book ID: " << chosenBook.getBookId() << endl
             << "Category: " << chosenBook.getCategory() << endl
             << "Year Published: " << chosenBook.getYearPublished() << endl;
        cout << "+ - - - - - - - - - - - - - +\n\n";

        chosenBook.borrow(studentId);
    }
};

void HomePage(Student &s1) {
    string name, idInput;

    cout << "Enter Student Name: ";
    getline(cin, name);

    while (true) {
        cout << "Enter Student ID (4 digits): ";
        getline(cin, idInput);

        if (idInput.length() != 4) {
            cout << "ID must be exactly 4 digits!\n";
        } else {
            break;
        }
    }

    s1.setName(name);
    s1.setId(stoi(idInput));

    cout << "\n+ - - - - - - - - - - - - - +\n\n";
    cout << "Log-in successful.\n";
    s1.displayInfo();
}

int main() {
    cout << "== Library System | HARDCORE EDITION | ==\n\n";

    Student student1;
    Library lib;
    int choice;

    do {
        HomePage(student1);
        cout << "\n+ - - - - - - - - - - - - - +\n\n";
        cout << "Books Available:\n";
        lib.displayBooks();
        cout << "\n+ - - - - - - - - - - - - - +\n";

        cout << "[1] Borrow | [2] Return | [3] Exit\n"
             << "Enter Choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(9999, '\n');

        if (choice == 1) {
            lib.borrowBook(student1.getId());
        } else if (choice == 2) {
            cout << "Return functionality not implemented yet.\n";
        } else if (choice == 3) {
            cout << "Exiting Program...\n";
            break;
        } else {
            cout << "Invalid input!\n";
        }

        cout << endl;

    } while (true);

    return 0;
}
