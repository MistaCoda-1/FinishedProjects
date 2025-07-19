#include <iostream>
#include <iomanip>
using namespace std;

    double gradeCalc(double a, double b, double c) {
        return (a + b + c) / 3;
    }

    bool realisticGrade(double grade) {
        return grade >= 0 && grade <= 100;
    }

    bool canPass(double aveGrade) {
        return (aveGrade >= 75);
    }

int main() {

    string name;
    double grades [3];
    double sumOfGrades = 0;


    cout << "Hey! Welcome to my grade calculator! \n";
    cout << "Just type in your info here: \n";
    cout << "Name: ";

    getline (cin, name);

    cout << "Nice meeting ya, " << name << "! Now just type in 3 of your grades! \n";

    for (int i = 0; i < 3; i++) {
        double inputGrade;

        while (true) {
            cout << "Enter grade " << i + 1 << ":" ;
            cin >> inputGrade;

            if (realisticGrade(inputGrade)) {
                grades[i] = inputGrade;
                break;
            } else {
                cout << "Please enter a real grade! (0 - 100)\n";
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        sumOfGrades += grades[i];
    }

    double averageGrade = sumOfGrades / 3;

    cout <<  "Your average grade is: " << fixed << setprecision(2) << averageGrade << endl;

    if (canPass(averageGrade)) {
        cout << "Congratulations you passed!";
    } else {
        cout << "Looks like you failed, better luck next time!";
    }

    return 0;
}