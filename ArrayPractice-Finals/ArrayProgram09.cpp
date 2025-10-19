#include <iostream>
using namespace std;

int main() {

    int warehouse[2][3][4];

    cout << "This is your warehouse! Let's do a simple storage check.\n\n";

    cout << "You start walking. . .\n";

    for (int i = 0; i < 2; i++) {
        cout << "\nYou're at floor [" << i + 1 << "] right now. ";
        for (int j = 0; j < 3; j++) {
            cout << "\nLet's check aisle [" << j + 1 << "]!\n\n";
            for (int k = 0; k < 4; k++) {
                cout << "Alright, how many boxes are on shelf [" << k + 1 << "]: ";
                cin >> warehouse[i][j][k];
            }
        }
    }

    int totalBoxes = 0;
    int mostBoxes = 0;
    int floorWithMost = 0;

    for (int i = 0; i < 2; i++) {
        int floorTotal = 0;

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                floorTotal += warehouse[i][j][k];
            }
        }

        cout << "\nTotal boxes on floor " << i + 1 << ": " << floorTotal;

        totalBoxes += floorTotal;   

        if (floorTotal > mostBoxes) {
            mostBoxes = floorTotal;
            floorWithMost = i + 1;
        }
    }

    cout << "\nTotal boxes: " << totalBoxes;
    cout << "\nFloor with most boxes: " << floorWithMost;

/*
    cout << "\n\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << warehouse[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
*/

    return 0;
}