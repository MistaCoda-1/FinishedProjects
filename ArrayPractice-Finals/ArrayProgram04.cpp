#include <iostream>
using namespace std;

int main() {

    int numbers[5];

    cout << "== Array reverser ==\n\n";

    cout << "Enter 5 integers!\n";

    for (int i = 0; i < 5; i++) {
        cout << "Enter number #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nArray in reverse: ";

    for (int i = 4; i >= 0; i--) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}