#include <iostream>
using namespace std;

int main() {

    cout << "== Largest Number Finder ==\n\n";
    
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    
    cout << "Enter 5 numbers!\n";
    
    for (int i = 0; i < size; i++) {
        
        cout << "Number " << i + 1 << ".) ";
        cin >> arr[i];
        
    }
    
    cout << endl;
    int largest = arr[0];
    //int smallest = arr[0]; for smallest number, just change the if condition to "<"
    
    for (int i = 0; i < size; i++) {
        
        if (arr[i] > largest) {
            largest = arr[i];
        }

    }
    
    cout << "The largest number is: " << largest << endl;

    return 0;
}