#include <iostream>
using namespace std;

bool authUserNumb(int accountNum, int accountPin);
void atmInterface(int &balance);

int main() {
    int x, y, balance = 10000;

    cout << "=== ATM Machine ===\n\n";

    cout << "Enter Account Number: ";
    cin >> x;

    cout << "Enter Pin: ";
    cin >> y;
    
    if (authUserNumb(x, y)) {
        atmInterface(balance);
    } else {
        cout << "Access denied.\n";
    }

    return 0;
}

bool authUserNumb(int accountNum, int accountPin) {
    if (accountNum == 123456789 && accountPin == 9932) {
        return true;
    } else {
        return false;
    }
}

void atmInterface(int &balance) {
    int choice;

    do {
        cout << "\nCurrent Balance: " << balance << endl;
        cout << "Withdraw [1] || Deposit [2] || Exit [3]: ";
        cin >> choice;

        if (choice == 1) {
            int toWithdraw;
            cout << "Enter amount to withdraw: ";
            cin >> toWithdraw;

            if (toWithdraw > balance) {
                cout << "Insufficient funds!\n";
            } else {
                balance -= toWithdraw;
                cout << "Withdrawal successful.\n";
            }

        } else if (choice == 2) {
            int toDeposit;
            cout << "Enter amount to deposit: ";
            cin >> toDeposit;

            if (toDeposit > 0) {
                balance += toDeposit;
                cout << "Deposit successful.\n";
            } else {
                cout << "Invalid deposit amount.\n";
            }

        } else if (choice == 3) {
            cout << "Program terminated.\n";
        } else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}
