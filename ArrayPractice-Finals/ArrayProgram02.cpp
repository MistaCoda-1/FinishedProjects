#include <iostream>
using namespace std;

int main() {

    int numbers[10];


    cout << "== Max & Min Finder ==\n\n";

    cout << "Enter 10 numbers!\n";

    for (int i = 0; i < 10; i++) {

        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];

    }

    int max = numbers[0]; 
    int min = numbers[0];
    
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    cout << "\nThe largest number is: " << max;
    cout << "\nThe smallest number is: " << min;

    return 0;
}