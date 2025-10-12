#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance = 1092;
    int accountNum = 232;
    int accountPass = 2332;
public:

    void getBal() {
        cout << "\nYou have P" << balance << " in your account!\n";
    }
    void withdraw() {
        int finalAmount, withdraw;

        cout << "\nEnter amount to Withdraw: ";
        cin >> withdraw;

        if (withdraw <= balance) {
    
            balance -= withdraw;

            cout << "\nYou withdrew P" << withdraw << " from your account!\n";
        } else {
            cout << "\nInsufficient Funds!\n";
        }
    }
    void deposit() {
        int deposit;
        cout << "\nEnter amount to Deposit: ";
        cin >> deposit;

        balance += deposit;

        cout << "\nYou deposited P" << deposit << " to your account!\n";
    }
    bool authenticate(int accNum, int accPass) {
        return (accNum == accountNum && accPass == accountPass);
    }
};

int main() {

    int accountNumber, accountPassword;

    cout << "=== BANK ACCOUNT SIMULATOR ===\n\n";

    cout << "Account Number: ";
    cin >> accountNumber;
    
    cout << "Account Password: ";
    cin >> accountPassword;

    BankAccount Account1;
    int menuChoice, amount;

    bool LoggedIn = Account1.authenticate(accountNumber, accountPassword);

    if (!LoggedIn) {
        cout << "\nINVALID CREDENTIALS!\n";
    } else {
        do {
            cout << "\n================\n";
            cout << "1 - Check Balance";
            cout << "\n2 - Withdraw";
            cout << "\n3 - Deposit";
            cout << "\n4 - Exit";
            cout << "\n================\n";
            cout << "Enter Choice: ";
            cin >> menuChoice;

            if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid Input. Try again.\n";
            continue;
            }

            switch (menuChoice) {
                case 1: Account1.getBal(); break;
                case 2: Account1.withdraw(); break;
                case 3: Account1.deposit(); break;
                case 4: cout<<"\nProgram Terminated\n"; LoggedIn = 0; break;
                default: cout<<"\nInvalid Input. Try again.\n";
            }
        } while (LoggedIn);
    }
    return 0;
}