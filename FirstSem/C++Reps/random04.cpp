#include<iostream>
#include<string>
using namespace std;

class Member {
private:

string member__name;
int member__id;

public:

void setUser() {
    cout << "Member Name: ";
    cin >> member__name;
    cout << "Member ID: ";
    cin >> member__id;
    cout << "------------------------------|\n";
}
string getName() {
    return member__name;
}
int getId() {
    return member__id;
}

};

class Book {
private:

string title;
string author;
string borrower;
bool borrowed;

public:

Book() {
    string title = "Unknown";
    string author = "Unknown";
    string borrower = "N/A";
    bool borrowed = false;
}
Book(string t, string a) {
    title = t;
    author = a;
    borrower = "";
    borrowed = false;
}
void display (int i) {
    cout << i + 1 << " - " << title << " by "
         << author << endl;
    if (borrowed) {
        cout << " [BORROWED BY " << borrower << "]" << endl;
    }
}
void returBook() {
    borrowed = false;
    borrower = "";
}
void borrowBook(string name) {
    borrowed = true;
    borrower = name;
}
string getTitle() {
    return title;
}
string getAuthor() {
    return author;
}

};

class Library {
private:

Book books[5] = {
    Book("Title 1", "Author 1"),
    Book("Title 2", "Author 2"),
    Book("Title 3", "Author 3"),
    Book("Title 4", "Author 4"),
    Book("Title 5", "Author 5")
};

public:

void displayBooks() {
    cout << "Book selection:\n";
    for (int i = 0; i < 5; i++) {
        books[i].display(i);
    }
    cout << "------------------------------|\n";
}
};

int main() {
    Member m1;
    Library lib;

    cout << "== Library Program ==\n\n";

    m1.setUser();

    lib.displayBooks();
    return 0;
}