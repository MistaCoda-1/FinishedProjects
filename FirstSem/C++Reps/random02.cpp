#include <iostream>
#include <string>
using namespace std;
//-------------------------------------------------------------//
class Member {
private:

string member__name;
int member__ID;

public:

void setUsername() {
    string name;
    cin >> name;
    member__name = name;
}

void setID() {
    int ID;
    cin >> ID;
    member__ID = ID;
}

string getName() {
    return member__name;
}

int getID() {
    return member__ID;
}

};
//-------------------------------------------------------------//
class Books {
private:

string title[5] = { "Book #1", "Book #2", "Book #3",
    "Book #4", "Book #5" };

string author[5] = { "Random #1", "Random #2", "Random #3",
    "Random #4", "Random #5" };

public:

string getTitle(int i) {
    return title[i];
}

string getAuthor(int i) {
    return author[i];
}

};
//-------------------------------------------------------------//

class Book {
private:

Books books;

string nameOf__Borrower;
int idOf__Borrower;
bool borrowed;

public:

bool isBorrowed() {
    return borrowed;
}

void borrow(string name, int id) {
    int temp;

    do {
        cout << "Enter book choice: ";
        cin >> temp;

        if (temp < 1 || temp > 5) {
            cout << "ERROR! Invalid Input!\n";
        }
    } while (temp < 1 || temp > 5);

    string t = books.getAuthor(temp - 1);
    string a = books.getTitle(temp - 1);

    nameOf__Borrower = name;
    idOf__Borrower = id;

    cout << "---------------------------------|\n";
    cout << "Borrow succesful! " << name << " borrowed:\n";
    cout << t << " by " << a << endl;
    cout << "---------------------------------|\n";
}

};
//-------------------------------------------------------------//
class Library {
private:

Books books;

public:

void showBooks() {
    cout << "Book Selection:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " - " << books.getTitle(i) << " by "
        << books.getAuthor(i) << endl;
    }
    cout << "---------------------------------|\n";
}

};
//-------------------------------------------------------------//
void borrowABook() {
    Book book;
    Member member;
    Library lib;

    cout << "---------------------------------|\n";
    cout << "Member Name: ";
    member.setUsername();
    cout << "Member ID: ";
    member.setID();
    cout << "---------------------------------|\n";

    string n = member.getName();
    int id = member.getID();

    lib.showBooks();
    book.borrow(n, id);
}
//-------------------------------------------------------------//
void returnABook() {

}
//-------------------------------------------------------------//
int main() {

    int choice;
    char retry;

    do {
        cout << "== Library Simulator ==\n\n";
    
        do {
            cout << "Borrow a Book [1] || Return a Book [2]: ";
            cin >> choice;
    
            if (choice == 1) {
                borrowABook();
            } else if (choice == 2) {
                
            } else {
                cout << "ERROR! Invalid input!\n";
            }
        } while (choice > 2);

        cout << "Go again?(y/n): ";
        cin >> retry;
        cout << endl;
    } while (retry == 'y' || retry == 'Y');


    return 0;
}
