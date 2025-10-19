#include <iostream>
using namespace std;

int main() {

    int size, sum = 0;

    cout << "== Average Calculator ==\n\n";

    cout << "Size of Array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl;

    for (int i = 0; i < size; i++) {

        sum += arr[i];

    }

    cout << "The average of the entered values are: " << sum / size;
    return 0;
}