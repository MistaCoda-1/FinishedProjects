#include <iostream>
using namespace std;

int main() {

    int array1[5] = {3, 2, 1, 4, 5};

    cout << "Array elements in reverse: ";

    for (int i = 4; i >= 0; i--) {
        cout << array1[i] << " ";
    }

    cout << endl;

    return 0;
}
