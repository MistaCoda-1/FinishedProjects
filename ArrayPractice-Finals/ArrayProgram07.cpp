#include <iostream>
using namespace std;

int main() {

    int matrix[3][3];

    cout << "== 3x3 Matrix ==\n\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j ++) {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j ++) {
            cout << matrix[i][j] << " ";
            sum += matrix[i][j];
        }
        cout << "| " << sum << endl;
    }

    return 0;
}