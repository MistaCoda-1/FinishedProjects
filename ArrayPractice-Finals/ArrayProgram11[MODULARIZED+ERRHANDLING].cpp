#include <iostream>
using namespace std;

string subject(int indicator) {
    switch (indicator) {
        case 0: return "English";
        case 1: return "Physics";
        default: return "Science";
    }
}

void inputGrades(int grades[][3][3], int n) {
    cout << "//==============\n";
        for (int i = 0; i < 2; i++) {
            cout << "\nSection " << i + 1 << "\n\n";
            for (int j = 0; j < n; j++) {
                cout << "Student " << j + 1 << ":\n";
                for (int k = 0; k < n; k++) {
                    int temp;
                    bool validInput;
                    string s = subject(k);
                    do {
                        cout << "  Subject [ " << s << " ] grade: ";
                        cin >> temp;
                        if (temp < 65 || temp > 100) {
                            cout << "  Error! Grades should be above 65 and below 100!\n";
                            validInput = false;
                        } else {
                            grades[i][j][k] = temp;
                            validInput = true;
                        }
                    } while (!validInput);
                }
            }
            cout << endl;
        }
    cout << "//==============\n\n";
}

void displayGrades(int grades[][3][3], int n) {
    cout << "== Grades Viewing ==\n\n";
    double overallSum = 0;
    for (int i = 0; i < 2; i++) {
        cout << "Section " << i + 1 << ":\n\n";
        double sumSect = 0;
        for (int j = 0; j < n; j++) {
            double sumStud = 0;
            for (int k = 0; k < n; k++) {
                sumStud += grades[i][j][k];
            }
            double studAve = sumStud / n;  
            sumSect += sumStud;
            cout << "Student " << j + 1 << " average: " << studAve << endl;
        }
        double sectAve = sumSect / (n * n);
        overallSum += sumSect;
        cout << "Section " << i + 1 << " average: " << sectAve << "\n\n";
    }
    double overallAve = overallSum / (2 * n * n);
    cout << "Overall Average of both sections: " << overallAve << "\n\n";
    cout << "//==============";

}

int main() {

    cout << "== Grades Analyzer 3D ==\n\n";

    int grades[2][3][3];
    int n = 3;

    inputGrades(grades, n);
    displayGrades(grades, n);

    cout << "\n\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << grades[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
