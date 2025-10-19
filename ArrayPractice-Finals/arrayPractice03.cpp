#include <iostream>
using namespace std;

int main() {
    int arr[11] = {3, 1, 5, 2, 4, 23, 23, 1, 52, 9452, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    
    
    // Sorting
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {

            if (arr[j] < arr[j + 1]) {

                // swap them
                int temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }

        }

    }

    cout << "Ascending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
