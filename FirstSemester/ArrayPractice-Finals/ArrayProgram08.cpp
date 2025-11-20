#include <iostream>
using namespace std;

int main() {

    string students[3];
    double grades[3][3];

    cout << "== Student Grade Average-er ==\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "Enter student name #" << i + 1 << ": ";
        cin >> students[i];
        for (int j = 0; j < 3; j++) {
            cout << "Enter subject grade #" << j + 1 << ": ";
            cin >> grades[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        double ave = 0;
        cout << "[" <<students[i] << "] has an average of: ";
        for (int j = 0; j < 3; j++) {
            ave += grades[i][j];
        }
        cout << ave / 3 << endl;
    }

    return 0;
}