#include <iostream>
using namespace std;

int main() {

    int numbers[8];
    int odds = 0, evens = 0;

    cout << "== Even & Odd numbers counter ==\n\n";

    cout << "Enter 8 integers!\n";
    
    for (int i = 0; i < 8; i++) {
        cout << "Enter integer #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    for (int i = 0; i < 8; i++) {
        if (numbers[i] % 2 == 0) {
            evens += 1;
        } else {
            odds += 1;
        }
    }

    cout << "\nEvens: " << evens << endl;
    cout << "Odds: " << odds << endl;

    return 0;
}