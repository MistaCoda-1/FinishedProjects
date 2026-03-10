#pragma once
using namespace std;

class Book {    // Base Class for all Book objects
    private:
        string title;
        string author;
        int pages;
        bool isBorrowed;
    public:
        // Default or Unparameterized Constructor
        Book() {    
            title = "";
            author = "";
            pages = 0;
            isBorrowed = false;
        }
        // Parameterized constructor
        Book(string t, string a, int p, bool b) :   
            title(t),
            author(a),
            pages(p),
            isBorrowed(b)
        { }
        // Helper function to avoid repitition
        void isAvail() const {
            cout << (borrowed() ? "[BORROWED]" : "[AVAILABLE]");
        }
        // Shows the object's internal information
        virtual void showInformation(int i) const {
            cout << "Book #" << i << "\n";

            cout << "Title: " << title << " | "
                << "Author: " << author << " | "
                << "Book Pages: " << pages << " | ";

            isAvail();
            cout << "\n";
        }

        void borrow() {     // Marks object as borrowed
            isBorrowed = true;
        }
        void returned() {   // Marks object as available
            isBorrowed = false;
        }

        // Getter functions
        string getTitle() const { return title; }
        string getAuthor() const { return author; }
        int getPageAmount() const { return pages; }
        bool borrowed() const { return isBorrowed; }

        virtual ~Book() = default;
};