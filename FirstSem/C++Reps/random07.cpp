#include<iostream>
#include<string>
using namespace std;

class User {
    private:
    // Handles sensitive data of users
        string User__Name;
        int User__ID;
    public:
    // Handles getting and setting user data
        User() {
            User__Name = "";
            User__ID = 000;
        }
        User(string username, int userid) {
            User__Name = username;
            User__ID = userid;
        }

        void setUsername(string username) {
            User__Name = username;
        }
        void setUserid(int id) {
            User__ID = id;
        }
        string getUsername() const {
            return User__Name;
        }
        int getUserid() const {
            return User__ID;
        }
    };

class User__Account {
    private:
    // Handles user balance/loan
        User account;
        int balance;
        int loan; 
    public:
    // Handles pay/loan/deposit/withdraw
        User__Account() {
            User();
            balance = 0;
            loan = 0;
        }
        User__Account(int bal, int loaned, int id, string name) {
            User(name, id);
            balance = bal;
            loan = loaned;
        }

        void setBal(int bal) {
            balance = bal;
        }
        void setLoan(int loaned) {
            loan = loaned;
        }
        int withdraw(int amount) {
            return balance - amount;
        }
        int deposit(int amount) {
            return balance + amount;
        }
        int getBal() const {
            return balance;
        }
        int getLoan() const {
            return loan;
        }
        string getName__account() {
            return account.getUsername();
        }
        int getID__account() {
            return account.getUserid();
        }
    };

class Record__Book {
    private:
    // Handles individual user accounts
        User__Account users[3] = {
            User__Account(1924, 10000, 3090, "Dominic"),
            User__Account(103, 3002, 3091, "Kym"),
            User__Account(3980, 0, 3092, "Gerald")
        };
    public:
    // Handles recording processes + log in
    bool memberLogin(int &accIndex) {
        cout << "Member Name: ";
        string userInput__name;
        cin >> userInput__name;
        
        bool found = false;
        for (int i = 0; i < 3; i++) {
            if (userInput__name == users[i].getName__account()) {
                accIndex = i;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Error! Username not found!\n";
            return false;
        }

        cout << "Member ID: ";
        int userInput__id;
        cin >> userInput__id;

        if (userInput__id != users[accIndex].getID__account()) {
            cout << "Error! Incorrect ID!\n";
            return false;
        }
        return true;
    }
    void accountDetails(int accIndex) {
        string name = users[accIndex].getName__account();
        int bal = users[accIndex].getBal();
        int loan = users[accIndex].getLoan();
        int id = users[accIndex].getID__account();

        cout << "Account Name: " << name << endl
             << "Account ID: " << id << endl
             << "Balance: P" << bal << endl
             << "Current Loan: P" << loan << endl;
        cout << "-----------------------------------|\n";
    }
    void logAction(int accIndex, int choice) {
        int amount;
        cin >> amount;
        if (choice == 0) {
            users[accIndex].deposit(amount);
            users[accIndex].setBal(amount);
        } else if (choice == 1) {
            users[accIndex].withdraw(amount);
            users[accIndex].setBal(amount);
        } else if (choice == 2) {
            int newLoan = users[accIndex].getLoan() + amount;
            users[accIndex].setLoan(newLoan);
        }
    }
};

struct UserInterface {
    Record__Book log;
    string options[3] = {
        "Deposit",
        "Withdraw",
        "Loan"
    };
    void show__MainPage() {
        cout << "== BANK SIMULATOR ==\n\n";

        cout << "What's our agenda today?" << endl;
    }
    void show__Options() {
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << " - "
                 << options[i] << endl;
        }
    }
    void show__Selection(int &choice) {
        cout << "Choose action: ";
        cin >> choice;
        cout << "-----------------------------------|\n";
    }
    void show__Login(bool &loggedIn, int &accIndex) {
        loggedIn = log.memberLogin(accIndex);
    }
    void show__Account(int accIndex) {
        log.accountDetails(accIndex);
    }
    void show__Choice(int accIndex, int choice) {
        cout << options[choice - 1] 
             << " amount: "; 
        log.logAction(accIndex, choice);
    }
};

int main() {
    UserInterface admin;
    int choice, accIndex;
    bool loggedIn;

    admin.show__Login(loggedIn, accIndex);
    while (loggedIn) {
        admin.show__MainPage();
        admin.show__Options();
        admin.show__Selection(choice);
        admin.show__Account(accIndex);
        admin.show__Choice(accIndex, choice);
    }


    return 0;
}