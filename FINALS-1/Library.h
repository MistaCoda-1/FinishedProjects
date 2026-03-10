#pragma once
using namespace std;

class Library {
    private:
        const int MAX_BOOKS = 10;

        vector<Book*> Books;
    public:
        bool isValidIndex(int i, const vector<Book*>& Books) {
            if (i < 0 || i >= Books.size()) {
                cout << "Invalid index!\n";
                cout << "| - - - - - - - - - - - - - - - - - |\n";
                return false;
            }
            return true;
        }

        void showBooks() const {
            cout << "| - - - - - - - - - - - - - - - - - |\n";
            for (int i = 0; i < Books.size(); i++) {
                Books[i]->showInformation(i+1);
            }
        }

        void addBook() {
            string title;
            string author;
            int pages;

            cout << "| - - - - - - - - - - - - - - - - - |\n";
            if (Books.size() >= MAX_BOOKS) {
                cout << "Library is full! Please remove a book first!\n";
            } else {
                cout << "Slot #" << Books.size() + 1 << " is free!\n";

                int choice;

                cout << "What type of book do you want to add?\n\n"
                     << "[1] Literature\n"
                     << "[2] Magazine\n";

                while (choice < 1 || choice > 2) {
                    cout << "Choose Book type: ";
                    cin >> choice;

                    if (choice < 1 || choice > 2) {
                        cout << "ERROR! Pick between 1 - 2!\n";
                        continue;
                    }
                    break;
                }

                cin.ignore(9999, '\n');

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Amount of Pages: ";
                cin >> pages;
                cin.ignore(9999, '\n');

                if (choice == 1) {
                    string genre;
                    string language;

                    cout << "Enter Genre: ";
                    getline(cin, genre);

                    cout << "Enter Language: ";
                    getline(cin, language);

                    Books.push_back(new Literature(title, author, pages, false, genre, language));
                } else if (choice == 2) {
                    int issueNo;
                    string topic;

                    cout << "Enter Issue Number: ";
                    cin >> issueNo;
                    cin.ignore(9999, '\n');

                    cout << "Enter Topic: ";
                    getline(cin, topic);

                    Books.push_back(new Magazine(title, author, pages, false, issueNo, topic));
                } else {
                    cout << "INVALID INPUT!\n";
                    return;
                }

                cout << "\nBook added successfully!\n\n";
            }
            cout << "| - - - - - - - - - - - - - - - - - |\n";
        }

        void removeBook() {
            int i;
            cout << "| - - - - - - - - - - - - - - - - - |\n";
            cout << "Enter a Book number to remove: ";
            cin >> i;
            i--;

            if (isValidIndex(i, Books)) {
                string removedTitle = Books[i]->getTitle();

                delete Books[i];
                Books.erase(Books.begin() + i);

                cout << "[ " <<removedTitle << " ] has been removed successfully.\n";
                cout << "| - - - - - - - - - - - - - - - - - |\n";
            }
        }

        void borrowBook() {
            int i;

            cout << "| - - - - - - - - - - - - - - - - - |\n";
            cout << "Enter Book number to borrow: ";
            cin >> i;
            i--;

            if (!isValidIndex(i, Books)) {
                return;
            }

            if (Books[i]->borrowed()) {
                cout << "That book is not available!\n";
                cout << "| - - - - - - - - - - - - - - - - - |\n";
                return;
            }

            Books[i]->borrow();

            cout << "You borrowed [ " << Books[i]->getTitle() << " ] by [ " << Books[i]->getAuthor() << " ]\n";
            cout << "| - - - - - - - - - - - - - - - - - |\n";
        }

        void returnBook() {
            int i;

            cout << "| - - - - - - - - - - - - - - - - - |\n";
            cout << "Enter Book number to return: ";
            cin >> i;
            i--;

            if (!isValidIndex(i, Books)) {
                return;
            }

            if (!Books[i]->borrowed()) {
                cout << "You can't return a book that hasn't been borrowed yet!\n";
                cout << "| - - - - - - - - - - - - - - - - - |\n";
                return;
            }

            Books[i]->returned();

            cout << "You returned [ " << Books[i]->getTitle() << " ] by [ " << Books[i]->getAuthor() << " ]\n";
            cout << "| - - - - - - - - - - - - - - - - - |\n";
        }

        void saveToFile(const string& filename) const {
            ofstream out(filename);
            if (!out) return;

            for (Book* b : Books) {
                if (Literature* lit = dynamic_cast<Literature*>(b)) {
                    out << "Literature|"
                        << lit->getTitle() << "|"
                        << lit->getAuthor() << "|"
                        << lit->getPageAmount() << "|"
                        << lit->borrowed() << "|"
                        << lit->getGenre() << "|"
                        << lit->getLanguage() << "\n";
                } 
                else if (Magazine* mag = dynamic_cast<Magazine*>(b)) {
                    out << "Magazine|"
                        << mag->getTitle() << "|"
                        << mag->getAuthor() << "|"
                        << mag->getPageAmount() << "|"
                        << mag->borrowed() << "|"
                        << mag->getIssueNo() << "|"
                        << mag->getTopic() << "\n";
                }
            }
        }

        void loadFromFile(const string& filename) {
            ifstream in(filename);
            if (!in) {
                cout << "Could not open file: " << filename << "\n";
                return;
            }

            // Clear existing books in vector to avoid duplicates
            for (Book* b : Books) {
                delete b;
            }
            Books.clear();

            string line;
            while (getline(in, line)) {
                if (line.empty()) continue;

                stringstream ss(line);
                string token;
                vector<string> tokens;

                // Split line by '|'
                while (getline(ss, token, '|')) {
                    tokens.push_back(token);
                }

                if (tokens.empty()) continue;

                string type = tokens[0];

                if (type == "Literature" && tokens.size() == 7) {
                    string title = tokens[1];
                    string author = tokens[2];
                    int pages = stoi(tokens[3]);
                    bool borrowed = (tokens[4] == "1");
                    string genre = tokens[5];
                    string language = tokens[6];

                    Books.push_back(new Literature(title, author, pages, borrowed, genre, language));
                }
                else if (type == "Magazine" && tokens.size() == 7) {
                    string title = tokens[1];
                    string author = tokens[2];
                    int pages = stoi(tokens[3]);
                    bool borrowed = (tokens[4] == "1");
                    int issueNo = stoi(tokens[5]);
                    string topic = tokens[6];

                    Books.push_back(new Magazine(title, author, pages, borrowed, issueNo, topic));
                }
                else {
                    cout << "Invalid line in save file: " << line << "\n";
                }
            }
            in.close();
        }
};