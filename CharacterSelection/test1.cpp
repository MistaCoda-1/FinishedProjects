#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

/*
| - - - - - - - - - - - - - - - - - - - - - - - - - -  |

Completed Logic:
    Authentication
    Registration
    Character Creation
    Character Showcase
    Save to file
    Load from file

Incomplete Logic:
    Loading money & level from file

| - - - - - - - - - - - - - - - - - - - - - - - - - -  |
*/

void homePage() { // PRINT HOMEPAGE
    cout << "| - RPG SIMULATOR!! - |\n\n";

    cout << "Welcome to the world of [ ]!\n\n"
         << "[1]Log-in\n"
         << "[2]Register\n"
         << "[3]Exit\n"
         << "Enter Choice: ";
}

void showLoginPrompt() { // PROMPT FOR LOGIN
    cout << "\n| - - - LOG IN - - - |\n"
         << "Enter Username: ";
}

void showRegisterPrompt() { // PROMT FOR REGISTER
    cout << "\n| - - - REGISTER - - - |\n"
         << "Enter Username: ";
}

void showChCreationPrompt() { // CHARACTER CREATION PROMPT
    cout << "\n| - - - CHARACTER CREATION - - - |\n"
         << "Enter Character Name: ";
}

void showChMenu() { // CHARACTER MENU
    cout << "\n| - - - CHARACTER MENU - - - |\n"
        << "[1] Create character\n"
        << "[2] Select character\n"
        << "[3] Log Out\n"
        << "Enter choice: ";
}

class Character { // CONTAINS CHARACTER INFORMATION
    private:
        string characterName;
        string characterClass;
        int characterLevel;
        int characterMoney;
    public:
        Character(string chName, string chClass)
        : characterName(chName), 
          characterClass(chClass), 
          characterLevel(0), 
          characterMoney(0) {}

        Character()
        : characterName("Nameless"), 
          characterClass("Classless"), 
          characterLevel(0), 
          characterMoney(0) {}

        string getChName() const { return characterName;}
        string getChClass() const { return characterClass;}
        int getChLevel() const { return characterLevel;}
        int getMoney() const { return characterMoney;}

        void setChName(string& n) { characterName = n; }
        void setChClass(string& c) { characterClass = c; }
        void setChLevel(int& l) { characterLevel = l; }
        void setChMoney(int& m) { characterMoney = m; }

        void dispCharInf() const {
            cout << "- Class:\t" << characterClass << "\n"
                 << "- Level:\t" << characterLevel << "\n"
                 << "- Money:\t" << characterMoney << "\n";
        }
};

class Account { // HOLDS ACCOUNT DETAILS
    private:
        int MAX_CHARACTERS = 2;

        vector<Character> characters;

        string username;
        string password;
    public:
        Account(string u, string p) : username(u), password(p) {}

        string getUsername() const { return username; }
    
        string getPassword() const { return password; }

        bool checkPassword(const string& temp) const {
            return temp == password;
        }

        bool maxChReached() const {
            return characters.size() >= MAX_CHARACTERS;
        }

        void addCharacter(const string& chName, const string& chClass) {
            characters.emplace_back(chName, chClass);
        }

        void addCharacter(const Character& c) {
            characters.push_back(c);
        }

        void showCharacters() const {

            if (characters.empty()) {
                cout << "You don't have any characters yet!\n";
            } else {
                int i = 1;
                for (const auto& c : characters) {
                    cout << "Character " << i << ": [" << c.getChName() << "]\n";
                    c.dispCharInf();

                    cout << "| - - - - - - - - - - - - |\n";
                    i++;
                }
            }
        }

        const vector<Character>& getCharacters() const { return characters; }
        vector<Character>& getCharacters() { return characters; }

};

class AccountRepository { // CONTAINS & MANAGE ACCOUNTS
    private:
        vector<Account> users;
    public:
        const Account* usernameExists(const string &temp) const {
            for (const auto& u : users) {
                string user = u.getUsername();

                if (temp == user) {
                    return &u;
                }
            }
            return nullptr;
        }
        
        Account* editAccount(const string &temp) {
            for (auto& u : users) {
                string user = u.getUsername();

                if (temp == user) {
                    return &u;
                }
            }
            return nullptr;
        }

        void addAccount(const string& u, const string& p) {
            users.emplace_back(u, p);
        }

        void saveToFile(const string& filename) const {
            ofstream out(filename);
            if (!out) return;

            for (const auto& acc : users) {

                out << acc.getUsername() << " " << acc.getPassword() << "\n";
                const auto& chars = acc.getCharacters();
                out << chars.size() << "\n";

                for (const auto& c : chars) {
                    out << c.getChName() << " "
                        << c.getChClass() << " "
                        << c.getChLevel() << " "
                        << c.getMoney() << "\n";
                }
            }
        }
        
        void loadFromFile(const string& filename) {
            ifstream in(filename);
            if (!in) return;

            users.clear();
            std::string username, password;

            while (in >> username >> password) {
                Account acc(username, password);

                size_t numChars;
                in >> numChars;
                in.ignore(); // skip newline

                for (size_t i = 0; i < numChars; ++i) {
                    std::string chName, chClass;
                    int level, money;
                    in >> chName >> chClass >> level >> money;
                    Character c(chName, chClass);
                    // set level/money manually
                    c.setChLevel(level);
                    c.setChMoney(money);
                    acc.addCharacter(c);
                }

                users.push_back(acc);
            }
}

};

const Account* authenticate(
    AccountRepository& repo,
    const string& username,
    const string& password
) { // AUTHENTICATE CREDENTIALS
    const Account* user = repo.usernameExists(username);

    if (!user)
        return nullptr;

    if (!user->checkPassword(password))
        return nullptr;

    return user;
}

int main() {
    bool loggedIn = true;
    int choice;

    int logAttempts = 0;
    const int MAX_ATTEMPTS = 3;

    AccountRepository accountHandler;

    string filename = "savefile.txt";
    accountHandler.loadFromFile(filename);

    do {
        homePage();
        cin >> choice;

        cin.ignore(9999, '\n');
        string user, pass;
        switch (choice) {
            case 1: { // LOGIN SEQUENCE
                showLoginPrompt();
                getline(cin, user);

                cout << "Enter Password: ";
                getline(cin, pass);

                const Account* currentUser = authenticate(accountHandler, user, pass);

                if (!currentUser) {
                    logAttempts++;
                    if (logAttempts >= MAX_ATTEMPTS) {
                        cout << "\nToo many failed attempts!\n"
                            << "Program Exiting . . .\n";
                        loggedIn = false;
                        break;
                    }

                cout << "\nInvalid credentials!\n"
                     << "Returning to homepage . . .\n\n";
                continue;
                }

                bool inGame = true;

                while (inGame) {
                int chSelect;

                showChMenu();
                cin >> chSelect;

                string charName;
                string charClass;
                
                cin.ignore(9999, '\n');
                
                    switch (chSelect) {
                        case 1: {

                            if (currentUser->maxChReached()) {
                                cout << "\nMaximum amount of characters reached!\n";
                                continue;
                            }

                            showChCreationPrompt();
                            getline(cin, charName);

                            cout << "Enter character class: ";
                            getline(cin, charClass);

                            Account* editableAccount = accountHandler.editAccount(currentUser->getUsername());
                            
                            editableAccount->addCharacter(charName, charClass);
                            accountHandler.saveToFile(filename);
                            cout << "\nCharacter creation complete!\n"
                                 << "Returning to character menu . . .\n";
                            continue;
                        }
                        case 2: {
                            cout << "\n| - - - CHARACTER SELECT - - - |\n";
                            currentUser->showCharacters();

                            cout << "\nJust pretend you played a game . . .\n"
                                 << "Returning to chracter menu . . .\n";
                            continue;
                        }
                        case 3 : {
                            cout << "\nExiting character menu . . .\n"
                                 << "Returning to homepage . . .\n\n";
                            inGame = false;
                            break;
                        }
                        default: {
                            cout << "Invalid Input!\n\n";
                            continue;
                        }
                    }
                    // End of nested switch case
                }
               break;
            }
            case 2: { // REGISTER SEQUENCE
                string confirmPassword;
                showRegisterPrompt();
                getline(cin, user);

                if (accountHandler.usernameExists(user)) { // Checks if username is taken
                    cout << "Username taken!\n"
                         << "Returning to homepage . . .\n\n";
                    continue;
                }

                cout << "Create Password: ";
                getline(cin, pass);

                cout << "Re-Enter Password: ";
                getline(cin, confirmPassword);

                if (pass != confirmPassword) { // Checks if passwords match
                    cout << "Passwords don't match!\n"
                         << "Returning to homepage . . .\n\n";
                    continue;
                }

                accountHandler.addAccount(user, pass);
                accountHandler.saveToFile(filename);
                cout << "\nAccount registered!\n"
                     << "Returning to homepage . . .\n\n";
            continue;
            }
            case 3: { // EXIT
                cout << "\nThank you for playing!\n"
                     << "Exiting game . . . \n";
            loggedIn = false;
            break;
            }
            default: {
                cout << "Invalid Input!\n\n";
                continue;
            }
        }
    } while (loggedIn);

    return 0;
}