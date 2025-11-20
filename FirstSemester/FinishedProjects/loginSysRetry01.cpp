#include <iostream>
using namespace std;

bool authUser(string user, string password);
void action(int x);

int main() {

    string user, pass;
    bool loggedIn;

    cout << "=== LOG-IN SYSTEM ===\n";

    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    loggedIn = authUser(user, pass);

    while (loggedIn) {
        int choice;
        cout << "Post [1] || Share [2] || Browse [3] || Log-Out [4]: ";
        cin >> choice;

        if (choice == 4) {
            cout << "\nLogging out . . .\n\n";
            loggedIn = false;
        } else {
            action(choice);
        }
    }
    return 0;
}

bool authUser(string user, string password) {
    if (user == "admin" && password == "1234") {
        cout << "\nWelcome admin!\n\n";
        cout << "What's our agenda today?\n";
        return true;
    } else {
        cout << "Username or Password is incorrect!";
        return false;
    }
}

void action(int x) {
    switch (x) {
        case 1:
        cout << "\nYou proceed to post random stuff online no one likes.\n\n";
        break;
        case 2:
        cout << "\nYou saw a funny meme your friend posted, and shared it on your page.\n\n";
        break;
        case 3:
        cout << "\nYou browsed the internet, only to find yourself listed on the black market.\n\n";
        break;
        default:
        cout << "\nYou were too stupid to pick a number between 1 and 3.\n\n";
    }
}
