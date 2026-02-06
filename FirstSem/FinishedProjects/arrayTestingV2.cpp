#include <iostream>
#include <string>
using namespace std;

bool validInput(string name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

void friendPicker(int choice, string friends[]) {
    switch (choice) {
    case 1:
        cout << "You picked: " << friends[0] << endl;
        break;
    case 2:
        cout << "You picked: " << friends[1] << endl;
        break;
    case 3:
        cout << "You picked: " << friends[2] << endl;
        break;
    default:
        cout << "No more friends :(";
    }
}

int main() {

    string friendList[3];

    cout << "Friend lister 9000!\n";
    cout << "Enter three of your friends' name!\n";

    for (int i = 0; i < 3; i++) {
        string friendName;
        while (true) {
            cout << "Friend " << i + 1 << ": ";
            getline (cin, friendName);

            if (validInput(friendName)) {
                friendList[i] = friendName;
                break;
            } else {
                cout << "No numbers allowed!\n";
            }
        }
    }

    int choice;

    cout << "Pick a friend! (1 - 3): ";
    cin >> choice;

    friendPicker(choice,friendList);


    return 0;
}