#include <iostream>
using namespace std;

string timeOfDay(int indicator) {
    if (indicator + 1 == 1) {
        return "Morning";
    } else if (indicator + 1 == 2) {
        return "Afternoon";
    } else {
        return "Evening";
    }
}

int main() {

    double temperature[3][3][3];
    int n = 3;

    cout << "== !Temperature Tracker! ==\n\n";

    cout << "Your task is to record temperatures in:\n";
    cout << "3 Days, 3 Rooms, 3 Times each!\n";
    cout << "Let's start!\n\n";

    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cout << "Room " << j + 1;
            for (int k = 0; k < n; k++) {
                string t = timeOfDay(k);

                cout << "\tEnter [" << t << "] temp: ";
                cin >> temperature[i][j][k];
            }
            cout << endl;
        }
    }

    cout << "== Temperature Records ==\n\n";

    //Process data

    double overallTemp = 0;

    for (int i = 0; i < n; i++) {   //Day
        double sumDay = 0;
        for (int j = 0; j < n; j++) {   //Room
            double sumRoom = 0;
            for (int k = 0; k < n; k++) {   //Time of day
                sumRoom += temperature[i][j][k];
            }

            double aveRoom = sumRoom / n;
            cout << "Room ["<< j + 1 << "] average temp: " << aveRoom << endl;

            sumDay += sumRoom;
        }

        double aveDay = sumDay / (n*n);
        cout << "Day ["<< i + 1 << "] average temp: " << aveDay << "\n\n";

        overallTemp += sumDay;
    }

    double overallAve = overallTemp / (n*n*n);

    cout << "Overall average temperature: " << overallAve << endl;

    cout << "\n===================";

    //SHOW FULL ARRAY
    cout << "\n\n";


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << temperature[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}