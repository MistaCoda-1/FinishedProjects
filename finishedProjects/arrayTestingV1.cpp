#include <iostream>
#include <iomanip>
using namespace std;

bool validInput(double a) {
    return a >= 0 && a <= 100;
}

int main() {

    cout << "Enter three grades here: \n";

    double arrayG[3];
    double arrayW[3];
    double sumG = 0;
    double sumW = 0;

    for (int i = 0; i < 3; i++) {
        double grades;
        while (true) {
            cout << "Enter grade " << i + 1 << ": ";
            cin >> grades;

            if (validInput(grades)) {
                arrayG[i] = grades;
                break;
            } else {
                cout << "Lying aren't we?" << endl;
            }
        }
    }
//
    for (int i = 0; i < 3; i++) {
        double weight;
        while (true) {
            cout << "Enter weight of grade " << i + 1 << ": ";
            cin >> weight;

            if (validInput(weight)) {
            arrayW[i] = weight;
            break;
            } else {
                cout << "You know you can't go over 100, right?\n";
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        sumW += arrayW[i];
    }

    if (sumW != 100) {
        cout << "The weights you entered didn't sum up to 100.";
    }

    double weightedTotal = 0;
    for (int i = 0; i < 3; i++) {
        weightedTotal += arrayW[i] * (arrayG[i] / 100);
    }

    cout << "\nWeighted average grade: " << fixed << setprecision(2) << weightedTotal << "\n";
//
    return 0;
}