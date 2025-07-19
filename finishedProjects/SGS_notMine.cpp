#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool realisticGrade(double grade) {
    return grade >= 0 && grade <= 100;
}

int main() {
    string name;
    int subjectsAmount;
    double runningWeightSum = 0;

    cout << "This is a weighted grade calculator!\n";
    cout << "What's your name?: ";
    getline(cin, name);

    cout << "Alright " << name << ", how many grades are we calculating?: ";
    cin >> subjectsAmount;

    // Create vectors with size after getting subjectsAmount
    vector<double> grades(subjectsAmount);
    vector<double> weights(subjectsAmount);

    // Grade input + validation
    for (int i = 0; i < subjectsAmount; i++) {
        double input;
        while (true) {
            cout << "Enter grade " << i + 1 << ": ";
            cin >> input;

            if (realisticGrade(input)) {
                grades[i] = input;
                break;
            } else {
                cout << "Please enter a real grade! (0 - 100)\n";
            }
        }
    }

    // Weight input + validation
    for (int i = 0; i < subjectsAmount; i++) {
        double input;
        while (true) {
            cout << "Enter weight for subject " << i + 1 << ": ";
            cin >> input;

            if (input < 0 || input > 100) {
                cout << "Weights should be between 0 and 100.\n";
                continue;
            }

            if (runningWeightSum + input <= 100) {
                weights[i] = input;
                runningWeightSum += input;
                break;
            } else {
                cout << "Woah there! You're going overboard " << name << "! Try a smaller number.\n";
            }
        }
    }

    // Final weighted average calculation
    double weightedTotal = 0;
    for (int i = 0; i < subjectsAmount; i++) {
        weightedTotal += grades[i] * (weights[i] / 100);
    }

    cout << "\nWeighted average grade: " << fixed << setprecision(2) << weightedTotal << "\n";

    return 0;
}
