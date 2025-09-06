#include <iostream>
using namespace std;

int main() {

    cout << "Review for switch case statements!\n" << endl;

    char vehicle;

    cout << "[C] = Car, [M] = Motorcycle\n\nWhat kind of vehicle do you own?: ";
    cin >> vehicle;

    switch (vehicle) {
        case 'C':
        cout << "You own a car.\n";
        break;
        case 'M':
        cout << "You own a motorcycle.\n";
        break;
        default:
        cout << "Choose a vehicle!\n";
    }

    return 0;
}