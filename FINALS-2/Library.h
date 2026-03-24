#pragma once
using namespace std;

class Library {
    private:
        const int MAX_BOOKS = 10;
        vector<Book*> Books;
    public:
        // Styling purposes :)
        void printSeparator() const {
            cout << "\n| - - - - - - - - - - - - - - - - - - |\n\n";
        }
        // Helper function used to check if the vector is empty.
        bool noBooks() const {
            if (Books.empty()) {
                cout << "There are no books in the library!\n";
                printSeparator();
                return true;
            }
            return false;
        }
        // Loops through the vector and displays each objects' information.
        void showBooks() const {
            int i = 1;
            printSeparator();
            for (Book* b : Books) {
                cout << i++ << " - ";
                b->showInformation();
                cout << (i <= Books.size() ? "\n" : "");
            }
            printSeparator();
        }
        // Function for adding books.
        void addBook() {
            if (Books.size() >= MAX_BOOKS) {    // Checks if the library is full.
                printSeparator();
                cout << "Library is full! Please remove a book!\n";
                printSeparator();
                return;
            }

            printSeparator();
            cout << "What type of Book do you want to add?\n"
                << "[1] Literature\n"
                << "[2] Magazine\n";

            int choice = 0;
            while (true) {
                cout << "\nChoose Book Type: ";
                cin >> choice;
                if (choice == 1 || choice == 2) break;
                cout << "\nERROR! Pick between 1 - 2!\n";
            }

            cin.ignore(9999, '\n');

            string title, author;
            cout << "\nEnter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);

            // Takes user input and determines which derived object to create.
            if (choice == 1) {
                createLitBook(title, author);
            } else {
                createMagBook(title, author);
            }
        }
        // Function for creating a literature book.
        void createLitBook(const string& t, const string& a) {
            string g, l;

            cout << "Enter Genre: ";
            getline(cin, g);
            cout << "Enter Language: ";
            getline(cin, l);

            Books.push_back(new Literature(t, a, true, g, l));

            cout << "\nBook Created Successfully!\n";

            printSeparator();
        }
        // Function for creating a magazine book.
        void createMagBook(const string& t, const string& a) {
            string magTopic;
            int issueNo;

            cout << "Enter Topic: ";
            getline(cin, magTopic);
            cout << "Enter Issue Number: ";
            cin >> issueNo;

            Books.push_back(new Magazine(t, a, true, magTopic, issueNo));

            cout << "\nBook Created Successfully!\n";

            printSeparator();
        }
        // Function to remove a specific book.
        void removeBook() {
            printSeparator();
            if (noBooks()) { return; }  // You can't remove something that doesn't exist yet.

            int i;
            cout << "Enter Book Index to Remove: ";
            cin >> i;
            --i;

            if (i < 0 || i >= Books.size()) {   // Error Handling
                cout << "\nInvalid Index!\n";
                printSeparator();
                return;
            }

            if (!Books[i]->isAvailable()) {     // Checks if the chosen is in the library and can be removed.
                cout << "\nThat book is currently being borrowed!\n";
                printSeparator();
                return;
            }

            cout << "\n[ " << Books[i]->getTitle() << " ] has been removed from the library!\n";
            printSeparator();

            delete Books[i];
            Books.erase(Books.begin() + i); // Finds the correct index of the book to be removed.
        }
        // Function for borrowing a specific book.
        void borrowBook() {
            printSeparator();
            if (noBooks()) { return; }  // You can't borrow something that doesn't exist yet.

            int i;
            cout << "Enter Book Index to Borrow: ";
            cin >> i;

            --i;

            if (i < 0 || i >= Books.size()) {   // Error handling again
                cout << "\nInvalid Index!\n";
                printSeparator();
                return;
            }

            if (!Books[i]->isAvailable()) {     // Checks if the chosen book is borrowed or not.
                cout << "\nThat book is not available!\n";
                printSeparator();
                return;
            }

            Books[i]->borrowBook();

            cout << "\nYou borrowed [ " << Books[i]->getTitle() << " ] by [ " << Books[i]->getAuthor() << " ]\n";
            printSeparator();
        }
        // Function for returning a specific book.
        void returnBook() {
            printSeparator();
            if (noBooks()) { return; }  // I'm not gonna repeat the same comments here lol.

            int i;
            cout << "Enter Book Index to Return: ";
            cin >> i;

            --i;

            if (i < 0 || i >= Books.size()) {   
                cout << "\nInvalid Index!\n";
                printSeparator();
                return;
            }

            if (Books[i]->isAvailable()) {  // Can't return a book that's yet to be borrowed.
                cout << "\nYou can't return a book that hasn't been borrowed yet!\n";
                printSeparator();
                return;
            }

            Books[i]->returnBook();

            cout << "\nYou returned [ " << Books[i]->getTitle() << " ] by [ " << Books[i]->getAuthor() << " ]\n";
            printSeparator();
        }
        // Save function
        void saveToFile(const string& filename) const {
            ofstream out(filename);
            if (!out) {
                cout << "ERROR! Unable to save data!\n";
            }

            for (Book* b : Books) {
                b->saveInformation(out);    // Check literature.h or magazine.h for more info.
            }
        }
        // Load Function
        void loadFromFile(const string& filename) {
            ifstream in(filename);
            if(!in) {
                cout << "ERROR! Unable to open/read file!\n";
                return;
            }

            for (Book* b : Books) {     // Clears all current books in the vector to avoid duplicates.
                delete b;
            }
            Books.clear();

            // Refer to README.txt for in-depth explanation.
            string line;
            while (getline(in, line)) {
                vector<string> tokens;
                size_t end;

                while ((end = line.find('|')) != string::npos) {
                    tokens.push_back(line.substr(0, end));
                    line.erase(0, end + 1);
                }
                
                tokens.push_back(line);

                string type = tokens[0];

                if (type == "Literature" && tokens.size() == 6) {
                    string title = tokens[1];
                    string author = tokens[2];
                    bool available = (tokens[3] == "1");
                    string genre = tokens[4];
                    string language = tokens[5];

                    Books.push_back(new Literature(title, author, available, genre, language));
                } else if (type == "Magazine" && tokens.size() == 6) {
                    string title = tokens[1];
                    string author = tokens[2];
                    bool available = (tokens[3] == "1");
                    string topic = tokens[4];
                    int issueNo = stoi(tokens[5]);

                    Books.push_back(new Magazine(title, author, available, topic, issueNo));
                } else {
                    cout << "INVALID BOOK TYPE DETECTED!\n";
                    return;
                }
            }
            in.close();
        }
};