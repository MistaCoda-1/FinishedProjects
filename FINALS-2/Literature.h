#pragma once
using namespace std;

class Literature : public Book {
    private:
        string genre;
        string language;
    public:
        Literature() : Book() {
            genre = "";
            language = "";
        }

        Literature(string bTitle, string bAuthor, bool bAvail, string bGen, string bLang) :
            Book("Literature", bTitle, bAuthor, bAvail),
            genre(bGen),
            language(bLang)
        { }

        void showInformation() const override {
            cout << getType() << " Book\n"
                 << "Title: " << getTitle() << " | "
                 << "Author: " << getAuthor() << " | "
                 << "Genre: " << genre << " | "
                 << "Language: " << language << " | ";

            cout << (isAvailable() ? "[AVAILABLE]" : "[BORROWED]");

            cout << "\n";
        }

        void saveInformation(ofstream& out) const override {
            out << "Literature|"
                << getTitle() << "|"
                << getAuthor() << "|"
                << isAvailable() << "|"
                << genre << "|"
                << language << "\n";
        }

        string getGenre() { return genre; }
        string getLang() { return language; }
};