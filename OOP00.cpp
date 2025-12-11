#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int studentId;
        string studentName;
    public:
        Student() {
            studentId = 0000;
            studentName = "";
        }
        Student(int i, string n) {
            studentId = i;
            studentName = n;
        }

        int getId() {
            return studentId;
        }
        string getName() {
            return studentName;
        }
        void setName(string n) {
            studentName = n;
        }
        void setId(int id) {
            studentId = id;
        }

        void displayInf() {
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
        Book() {
            title = "";
            author = "";
            bookId = 0;
            borrowState = false;
            borrowerId = 0;

            category = "";
            yearPublished = "00/00/0000";
        }

        Book(string t, string a, int bookId, string c, string yearPub) {
            title = t;
            author = a;
            bookId = bookId;
            borrowState = false;
            borrowerId = 0000;

            category = c;
            yearPublished = yearPub;
        }

        void displayInf() {
            cout << title << endl;
        }

        string getTitle() {
            return title;
        }
        string getAuthor() {
            return author;
        }
        int getBookId() {
            return bookId;
        }
        bool getBorrState() {
            return borrowState;
        }
        int getBorrId() {
            return borrowerId;
        }
        string getCategory() {
            return category;
        }
        string getYearPub() {
            return yearPublished;
        }
};

class Library {
    private:
        Book books[3] = {
            Book("The man who moved.", "Socrates", 0001, "History", "01/27/1003"),
            Book("The man who couldn't move.", "Socrates", 0002, "History", "05/12/1004"),
            Book("The man who moved it.", "Socrates", 0003, "History", "09/03/1002")
        };
        int maxBooks = 3;
    public:
        void displayBooks() {
            for (int i = 0; i < maxBooks; i ++) {
                cout << "[" << i + 1 << "] - ";
                books[i].displayInf();
            }
        }

        void borrowBook() {
            
        }
};

void HomePage(Student &s1) {
    string n, i;

    cout << "Enter Student Name: ";
    getline(cin, n);
    
    do {
        cout << "Enter Student ID: ";
        getline(cin, i);

        if (i.length() > 4) {
            cout << "ID must only have 4 Digits!\n";
        } else if (i.length() < 4) {
            cout << "ID must have 4 Digits!\n";
        } else {
            break;
        }
    } while (i.length() != 4);
    
    s1.setName(n);
    s1.setId(stoi(i));

    cout << "\n+ - - - - - - - - - - - - - +\n\n";

    cout << "Log-in successful.\n"; 
    s1.displayInf();
}



int main() {

    cout << "== Library System | HARDCORE EDITION | ==\n\n";

    Student s1;
    Library lib;

    HomePage(s1);

    char c;
    cout << "\n+ - - - - - - - - - - - - - +\n\n";
    cout << "Books Available:\n";
    lib.displayBooks();
    cout << "\n+ - - - - - - - - - - - - - +\n";

    cout << "[1] Borrow || [2] Return\n";
    cin >> c;

    if (c == 1) {
        
    } else if (c == 2) {

    }

    return 0;
}