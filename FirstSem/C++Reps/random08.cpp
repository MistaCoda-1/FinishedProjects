#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

    vector<string> names;
    names.push_back("Dominic");
    names.push_back("Kym");
    names.push_back("Gerald");

    cout << "The size of this vector is currently [" << names.size() << "]\n\n";

    int choice;
    cout << "Do you want to modify the size of the vector?\n"
         << " Add Elements [1]\n"
         << " Remove Elements [2]\n"
         << "Choose action: ";

         cin >> choice;
    cout << "------------------------------------------|\n";
    if (choice == 1) {
        int amount;
        cout << "How many elements do you want to add?: ";
        cin >> amount;

        for (int i = 0; i < amount; i++) {
            string element;
            cout << "Enter Element #" << i + 1 << ": ";
            cin >> element;
            names.push_back(element);
        }
        cout << "Elements succesfully added.\n";
        cout << "------------------------------------------|\n";
    } else if (choice == 2) {

        int amount;
        bool validInput = false;

        cout << "How many elements do you want to remove?: ";
        cin >> amount;
        if (amount > names.size()) {
            amount = names.size();
        }

        for (int i = 0; i < amount; i++) {
            names.pop_back();
        }
        cout << amount << " Elements have been removed.\n";
        cout << "------------------------------------------|\n";
    } else {
        cout << "bruh";
        return false;
    }

    cout << "The size of this vector is currently [" << names.size() << "]\n\n";
    int index = 1;
    for (const auto& n : names) {
        cout << "User #" << index  
             << " - " << n << endl;
        index++;
    }

    return 0;
}