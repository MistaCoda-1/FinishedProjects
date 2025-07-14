#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

    bool credCheck (string uName, string passW) {
        if (uName == "admin" && passW == "1234") {
            cout << "Welcome back, Dominic!";
            return true;
        } else {
            return false;
        }
    }

    bool reLog () {
        string uName, passW;
        char retry;

        do {
        cout << "Invalid credentials!" << endl;
        cout << "Retry log-in? (y/n): " << flush;
        retry = _getch();
        cout << retry << endl;

            if (retry == 'y' || retry == 'Y') { 
            cout << "Username/E-mail: ";
            cin >> uName;
            cout << "Password: ";
            cin >> passW;
            } else {
                return false;
            }
        } while (!credCheck(uName, passW));
    }

int main() {

    string uName, passW;

    cout << "Welcome to 'FaceBook'! \n";
    cout << "Please enter your credentials: \n";
    cout << "Username/E-mail: ";
    cin >> uName;
    cout << "Password: ";
    cin >> passW;

    if (!credCheck(uName, passW)) {
        reLog();
    }
    return 0;
}