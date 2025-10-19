#include <iostream>
using namespace std;

int main() {

    int array2[5];

    cout << "Enter 5 numbers!\n";


    for(int i = 0; i < 5; i++) {
        cout << i + 1 <<". ";
        cin >> array2[i];
    }

    cout << endl;
    
    cout << "Chronological Order: ";

    for (int i = 0; i < 5; i++) {
        cout << array2[i] << " ";
    }
    
    cout << "\nReverse Order: ";
    
    for (int i = 4; i >= 0; i--) {
        cout << array2[i] << " ";
    }

    cout << endl;

    return 0;
}