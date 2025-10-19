#include <iostream>
using namespace std;

int main() {

    int arr1[2][2];
    int arr2[2][2];

    cout << "== 2x2 Matrices Sum ==\n\n";

    cout << "Table 1 values:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j ++) {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> arr1[i][j];
        }
        cout << endl;
    }

    cout << "\nTable 2 values:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j ++) {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> arr2[i][j];
        }
        cout << endl;
    }

    int t1Sum = 0, t2Sum = 0;

    cout << "Table 1:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j ++) {
            cout << arr1[i][j] << " ";

            t1Sum += arr1[i][j];
        }
        cout << endl;
    }

    cout << "Sum of table 1: " << t1Sum << endl;

    cout << "Table 2:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j ++) {
            cout << arr2[i][j] << " ";

            t2Sum += arr2[i][j];
        }
        cout << endl;
    }

    int finalSum = t1Sum + t2Sum;

    cout << "Sum of table 2: " << t2Sum << endl;

    cout << "\nSum of both tables: " << finalSum << endl;

    return 0;
}