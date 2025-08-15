#include <iostream>
using namespace std;

int main() {
    int numberArray[3];

    cout << "Number sorter 3000!\nAll your sorting problems are no more";
    cout << ", just type in 3 numbers and I'll sort it in ascending fashion!\n";

    // Input section

    for (int i = 0; i < 3; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numberArray[i];
    }

    // This section is pretty confusing,
    // The outer [ for loop ] controls how many passes we make
    // The inner [ for loop ] compares adjacent elements and swaps them if out of order

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (numberArray[j] > numberArray[j + 1]) {     // if left number is greater than right, swap
                int temp = numberArray[j];                 // set `temp` as number inside index[1]
                numberArray[j] = numberArray[j + 1];       // swap the two values so the smaller one comes first
                numberArray[j + 1] = temp;                 // I think this should be obvious.
            }
        }
    }

    // Output sorted array

    cout << "\nSorted Numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << numberArray[i] << " ";
    }
}