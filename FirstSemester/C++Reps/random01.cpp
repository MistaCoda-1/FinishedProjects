#include <iostream>
using namespace std;

struct Student {

int sectionSize;
const int subjects = 3;


void displayInputs__sectionSize() {

    cout << "Enter number of students: ";
    cin >> sectionSize;

}

void displayGrades() {

    string names[sectionSize];
    int grades[sectionSize][subjects];

    bool validInput;

    for (int i = 0; i < sectionSize; i++) {
        cout << "\n== STUDENT #" << i + 1 <<" ==\n";
        cout << "Name: ";
        cin >> names[i];
        cout << "Enter 3 Grades:\n";

        for (int j = 0; j < subjects; j++) {
            int temp = 0;
            do {
                cout << " - ";
                cin >> temp;

                if (temp < 65 || temp > 100) {
                    cout << "ERROR! Invalid Grade!\n";
                    validInput = false;
                } else {
                    grades[i][j] = temp;
                    validInput = true;
                }
            } while (!validInput);
        }
    }

    cout << "---------------------------------------------\n";
    cout << "Name\t\tAverage\t\tRemarks" << endl;

    for (int i = 0; i < sectionSize; i++) {
        cout << names[i] << "\t\t";
        int studentSum = 0;

        for (int j = 0; j < subjects; j++) {
            studentSum += grades[i][j];
        }
        double studentAverage = studentSum / subjects;

        cout << studentAverage << "\t\t";

        if (studentAverage >= 65) {
            cout << "Passed\n";
        } else {
            cout << "Failed\n";
        }
    }
    cout << "---------------------------------------------\n";
}
};

int main() {

    char again;

    do {
    Student student1;
    student1.displayInputs__sectionSize();
    student1.displayGrades();

    cout << "\nGo again?: ";
    cin >> again;
    cout << "\n";
    } while (again == 'y' || again == 'Y');


    return 0;
}
