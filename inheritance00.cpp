#include<iostream>
#include<vector>
using namespace std;

class Book {
    private:
        string title;
        string author;
        int pages;
    public:
        Book(string t, string a, int p) : // Parameterized Constructor
            title(t), 
            author(a), 
            pages(p) {}

        Book() : // Empty or Default Constructor
            title("???"), 
            author("???"), 
            pages(0) {}
        
        virtual void displayInfo() const {
            cout << "- Book Title:\t" << title << "\n"
                 << "- Book Author:\t" << author << "\n"
                 << "- Book Pages:\t" << pages << "\n";
        }
        
        string getTitle() const { return title; }
        string getAuthor() const { return author; }
        int getPages() const { return pages; }

        virtual ~Book() = default;
};

class Magazine : public Book {
    private:
        string genre;
    public:
        Magazine(string t, string a, int p, string g) :
            Book(t, a, p),
            genre(g)
        {}

        virtual void displayInfo() const override {
            cout << "- Magazine Title:\t" << getTitle() << "\n"
                 << "- Magazine Author:\t" << getAuthor() << "\n"
                 << "- Magazine Pages:\t" << getPages() << "\n"
                 << "- Magazine Genre:\t" << genre << "\n";
        }
};

int main() {

    cout << "| - Create your own magazine, or something - |\n\n";

    Book book1("The Book of all Books : Bookery", "Bookworm", 1932);
    Magazine magazine1("The Man Who Can't be Moved'nt", "Dominic", 183, "Satire");

    cout << "Book Information:\n";
    book1.displayInfo();

    cout << "| - - - - - - - - - - - - - - |\n";

    cout << "Magazine Information:\n";
    magazine1.displayInfo();

    return 0;
}