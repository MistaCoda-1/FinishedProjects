#include <iostream>
#include <string>
using namespace std;

int main() {

    int grades[4][2][3][3];
    string quarters[4] = { "FIRST", "SECOND", "THIRD", "FOURTH" };
    string subjects[3] = { "English", "Physics", "Science" };
    int n = 3;
    
    for (int i = 0; i < 4; i++) {   //Quarter
        cout << quarters[i] << " QUARTER\n";
        for (int j = 0; j < 2; j++) {   //Section
            cout << " Section " << j + 1 << ":\n";
            for (int k = 0; k < n; k++) {   //Student
                cout << "  Student " << k + 1 << ":\n";
                for (int o = 0; o < n; o++) {   //Subject Grade
                    cout << "   Enter [" << subjects[o] << "] grade: ";
                    cin >> grades[i][j][k][o];
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    //Data processing
    //-Student Averages ~
    //-Section Averages ~
    //-Quarter Averages ~

    //-Semester Average (per student)
    //-Semester Average (per student:subject)
    //-School Average (All students) ~

    double schoolSum = 0;

    cout << "== Semster Summaries ==\n\n";

    for (int i = 0; i < 4; i++) {   //Quarter
        double quarterSum = 0;
        for (int j = 0; j < 2; j++) {   //Section
            double sectionSum = 0;
            for (int k = 0; k < n; k++) {   //Student
                double studentSum = 0;
                for (int o = 0; o < n; o++) {   //Subject Grade
                    studentSum += grades[i][j][k][o];
                }
                double studentAve = studentSum / n;
                sectionSum += studentAve;

                cout << "  Student " << k + 1 << " Average: " << studentAve << endl;
            }
            double sectionAve = sectionSum / n;
            quarterSum += sectionAve;

            cout << "Section " << j + 1 << " Average: " << sectionAve << endl;
        }
        double quarterAve = quarterSum / 2;
        schoolSum += quarterAve;
        cout << "\n" << quarters[i] << " QUARTER Average: " << quarterAve << "\n\n//=================//\n\n";
    }

    double schoolAve = schoolSum / 4;
    cout << "\nSchool's Average Grade: " << schoolAve << "\n\n";

    //SHOW FULL ARRAY
    for (int i = 0; i < 4; i++) {   //Quarter
        for (int j = 0; j < 2; j++) {   //Section
            for (int k = 0; k < n; k++) {   //Student
                for (int o = 0; o < n; o++) {   //Subject Grade
                    cout << grades[i][j][k][o] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}