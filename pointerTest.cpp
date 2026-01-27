#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "| - POINTER TEST - |\n\n";

    int arr[3] = { 1, 2, 3};
    int *ptrArr[3];

    cout << "Memory addresses\n";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " -> " << &arr[i] << "\n";

        ptrArr[i] = &arr[i];
    }

    cout << "\nPointers to adresses:\n";
    for (auto p : ptrArr) {
        cout << p << " <- " << *p << "\n";
    }
    
    int newPtr;
    cout << "Change `*ptrArr[0]` to something else: ";
    cin >> newPtr;

    ptrArr[0] = &arr[newPtr - 1];

    cout << "\n\n\n\n";

    cout << "Memory addresses\n";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " -> " << &arr[i] << "\n";

        ptrArr[i] = &arr[i];
    }

    cout << "\nPointers to adresses:\n";
    for (auto p : ptrArr) {
        cout << p << " <- " << *p << "\n";
    }

    return 0;
}