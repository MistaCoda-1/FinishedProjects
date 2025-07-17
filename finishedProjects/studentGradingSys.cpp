#include <iostream>
#include <iomanip>
using namespace std;

    double gradeCalc(double a, double b, double c) {
        return (a + b + c) / 3;
    }

    bool canPass(double aveGrade) {
        (aveGrade >= 75);
    }

int main() {

    string name;
    double g1, g2, g3;
    double averageGrade = gradeCalc(g1, g2, g3);

    cout << "Hey! Welcome to my grade calculator! \n";
    cout << "Just type in your info here: \n";
    cout << "Name: ";

    getline (cin, name);

    cout << "Nice meeting ya, " << name << "! Now just type in 3 of your grades: \n";
    cin >> g1 >> g2 >> g3;

    cout <<  "Your average grade is: " << fixed << setprecision(2) << averageGrade << endl;

    if (canPass(averageGrade)) {
        cout << "Congratulations you passed!";
    } else {
        cout << "Looks like you failed, better luck next time!";
    }

    return 0;
}
