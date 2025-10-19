#include <iostream>
using namespace std;

int main() {
/*

//For hardcoded values

int arr[2][3][4] = {
    //Layer 0
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    },
    //Layer 1
    {
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    }
};

*/

//For user input

int arr[2][3][4];

for (int layer = 0; layer < 2; layer++) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << "Enter value for [" << layer << "][" << row << "][" << col << "]: ";
            cin >> arr[layer][row][col];
        }
        cout << endl;
    }
    cout << endl;
}

//Show array

cout << "\n== SHOW 3D ARRAY ==\n";

for (int layer = 0; layer < 2; layer++) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << arr[layer][row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

    return 0;
}