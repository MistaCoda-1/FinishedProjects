#include <iostream>
using namespace std;

int main() {

    int numberArray[3];
    int arraySum = 0;

    for (int i = 0; i < 3; i++) {
        int number;
        while (true) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> number;
            numberArray[i] = number;
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        arraySum += numberArray[i];
    }

    cout << "\nSum: " << arraySum;

    return 0;
}