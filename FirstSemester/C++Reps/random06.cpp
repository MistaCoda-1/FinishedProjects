#include<iostream>
#include<string>
using namespace std;

class Member {
    private:
    // Private will handle user data like:
    // Name and Member ID
        string Member__Name;
        int Member__Id;
    public:
    // Public will handle giving the data back to the program
    // Getter and Setter functions
    // + Constructors /-Used to quickly create a "Member" object-/
        Member() {
            Member__Name = "Unknown";
            Member__Id = 0000;
        }
        Member(string name, int ID) {
            Member__Name = name;
            Member__Id = ID;
        }

        void setName__Member(string name) {
            Member__Name = name;
        }
        void setId__Member(int ID) {
            Member__Id = ID;
        }
        string getName__Member() {
            return Member__Name;
        }
        int getID__Member() {
            return Member__Id;
        }
};

class Book {
    private:
    // Private will handle book data such as:
    // Title, Author, Borrower
    // Borrowed/Returned
        string title;
        string author;
        string borrower;
        bool borrowed;
    public:
    // Public will handle the objects data to determine:
    // Borrowed or not
    // Who borrowed it
        Book() {
            title = "Unknown";
            author = "Unknown";
            borrower = "Unknown";
            borrowed = false;
        }
        Book(string t, string a) {
            title = t;
            author = a;
            borrower = "";
            borrowed = false;
        }

        void display__Book(int i) {
            cout << i + 1 << " - \"" << title << "\" by " << author;
            if (borrowed)
                cout << "[BORROWED BY " << borrower << "]";
        }

        void setTitle__Book(string t) {
            title = t;
        }
        void setAuthor__Book(string a) {
            author = a;
        }
        void setBorrower__Book(const string &memberName) {
            borrowed = true;
            borrower = memberName;
        }
        void returnBook() {
            borrower = "";
            borrowed = false;
        }

        bool isBorrowed() {
            return borrowed;
        }
        string getTitle__Book() {
            return title;
        }
        string getAuthor__Book() {
            return author;
        }
        string getBorrower__Book() {
            return borrower;
        }
};

class Library {
    private:
    // Private will record the books that have been borrowed/returned
    // Fixed amount of 5 Books
        Book books[5] = {
            Book("The man who can't be moved", "Socrates"),
            Book("The man who can be moved", "Plato"),
            Book("The man who moved", "Aristotle"),
            Book("who moved", "Einstein"),
            Book("The", "Hercules")
        };
        int MaxBooks = 5;
    public:
    // Public will handle book displaying, and handle "Book" objects
        void displayBooks__Library() {
            cout << "\nBook shelf:" << endl;
            for (int i = 0; i < MaxBooks; i++) {
                books[i].display__Book(i);
                cout << endl;
            }
            cout << "------------------------------------|\n";
        }
        bool borrowBook__Library(Member &member, int bookChoice) {
            if (bookChoice < 1 || bookChoice > MaxBooks) {
                cout << "Error! Invalid Input!\n";
                return false;
            }

            Book &chosenBook = books[bookChoice - 1];
            if (chosenBook.isBorrowed()) {
                cout << "Sorry, " << "[" 
                     << chosenBook.getBorrower__Book()
                     << "] already borrowed that book.\n";
                    return false;
            }

            chosenBook.setBorrower__Book(member.getName__Member());

            cout << "\n== Borrow Succesful! ==\n"
                 << "Borrow Receipt:" << endl
                 << "Member: " << chosenBook.getBorrower__Book() << endl
                 << "Title: " << chosenBook.getTitle__Book() << endl
                 << "Author: " << chosenBook.getAuthor__Book() << endl;
            cout << "------------------------------------|\n";
            return true;
        }
        bool returnBook__Library(Member &member, int bookChoice) {
            if (bookChoice < 1 || bookChoice > MaxBooks) {
                cout << "Error! Invalid Input!\n";
                return false;
            }

            Book &chosenBook = books[bookChoice - 1];

            string borrowerOfBook = chosenBook.getBorrower__Book();
            string personReturningBook = member.getName__Member();
            bool samePerson;
            if (borrowerOfBook == personReturningBook) {
                samePerson = true;
            } else {
                samePerson = false;
            }

            if (!chosenBook.isBorrowed()) {
                cout << "------------------------------------|\n";
                cout << "The chosen book has not been borrowed yet,\n"
                     << "therefore can't be returned.\n";
                cout << "------------------------------------|\n";
                return false;
            } else if (!samePerson) {
                cout << "------------------------------------|\n";
                cout << "You're not that guy pal, trust me\nYou're not that guy.\n";
                cout << "------------------------------------|\n";
                return false;
            } else {
                cout << "------------------------------------|\n";
                cout << "Book returned succesfully!" << endl;
                cout << "------------------------------------|\n";
                chosenBook.returnBook();
                return true;
            }
        }
};

int main() {

    cout << "== Library ==\n\n";
    Library lib;
    string name;
    int id, choice;
    char again;

    do {
        cout << "------------------------------------|\n";
        cout << "Member Name: ";
        cin >> name;
        cout << "Member ID: ";
        cin >> id;
        cout << "------------------------------------|\n";
        Member member1(name, id);
    
        cout << "Logged in as, " << endl << member1.getName__Member() 
             << " [" << member1.getID__Member() << "]" << endl;
    
        int bookChoice;
        lib.displayBooks__Library();
        cout << "Borrow book[1] || Return book[2]" << endl;
        cout << "Choose action: ";
        cin >> choice;
        
        cout << "Choose a book (1 - 5): ";
        cin >> bookChoice;
    
        if (choice == 1)
            lib.borrowBook__Library(member1, bookChoice);
        else if (choice == 2)
            lib.returnBook__Library(member1, bookChoice);
        else
            return false;
        
        cout << "Go again?(y/n): ";
        cin >> again;
        cout << "\n\n\n\n";
    } while (again == 'y' || again == 'Y');
    return 0;
}