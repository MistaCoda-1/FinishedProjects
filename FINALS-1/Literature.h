#pragma once
using namespace std;

class Literature : public Book {    // Derived class of Book : Literature Books
    private:
        string genre;
        string language;
    public:
        Literature() : Book() {
            genre = "";
            language = "";
        }
        Literature(string t, string a, int p, bool b, string g, string l) : 
            Book(t, a, p, b),   // Initiate base class before anything else
            genre(g),
            language(l)
        { }

        // Overrides base function to show it's own data before everything else
        void showInformation(int i) const override {    
            cout << "Literature - Book #" << i << "\n";

            cout << "Genre: " << genre << " | "
                 << "Language: " << language << "\n";

            cout << "Title: " << getTitle() << " | "
                << "Author: " << getAuthor() << " | "
                << "Book Pages: " << getPageAmount() << " | ";

                isAvail();

                cout << "\n";
            cout << "| - - - - - - - - - - - - - - - - - |\n";
        }

        // Getter functions
        string getGenre() const { return genre; }
        string getLanguage() const { return language; }
};