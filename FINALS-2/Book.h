#pragma once
using namespace std;

// Base class of all Book Objects
class Book {
    private:
        string type;
        string title;
        string author;
        bool available;
    public:
        Book() {
            type = "";
            title = "";
            author = "";
            available = true;
        }

        Book(string bType, string bTitle, string bAuthor, bool bAvail) :
            type(bType),
            title(bTitle),
            author(bAuthor),
            available(bAvail)
        { }

        // Pure Virtual Functions
        virtual void showInformation() const = 0;
        virtual void saveInformation(ofstream& out) const = 0;

        void borrowBook() { available = false; }
        void returnBook() { available = true; }

        string getType() const { return type; }
        string getTitle() const { return title; }
        string getAuthor() const { return author; }
        bool isAvailable() const { return available; }

        virtual ~Book() = default;
};