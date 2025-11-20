#include <iostream>
#include <iomanip>
using namespace std;

struct Friend {
    string name;
    int age;
    string hobby;
};

void displayFriends(Friend friends[], int size);

int main() {

    Friend friends[4] = {
        {"Dominic", 19, "Programming"},
        {"Selene", 21, "Reading"},
        {"Miku", 16, "Singing"},
        {"Teto", 31, "Screaming"}
    };
    int sortBy;

    cout << "Friend List Sorter\n" << endl;
    cout << "[1] Alphabetical (Ascending)\t[2] Age (Ascending)\n";
    cout << "[3] Alphabetical (Descending)\t[4] Age (Descending)\n";
    cout << "Sort By: ";
    cin >> sortBy;
    cout << endl;

    switch (sortBy) {
        case 1:
            displayFriends(friends, 4);
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:

        break;
    }

    return 0;
}

void displayFriends(Friend friends[], int size) {
    cout << left << setw(12) << "Name"
         << setw(6) << "Age"
         << setw(15) << "Hobby" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(12) << friends[i].name
             << setw(6) << friends[i].age
             << setw(15) << friends[i].hobby << endl;
    }
}