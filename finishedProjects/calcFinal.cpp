#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

    int a;
    int b;
    char op;

    double opChecker (double a, double b) {
        double result;
        if (op == '+') {
            result = a + b;
        } else if (op == '-') {
            result = a - b;   
        } else if (op == '*') {
            result = a * b;
        } else if (op == '/') {
            result = a / b;
        } else {
            cout << "Do you not know what an operator is?" << endl;
            Sleep(2000);
            exit(0);
        }
        return result;
    }

    /*Operation Checker Module ^*/
    //Checks if the User typed a real operation.

    double intChecker(string prompt) {
        double num1;

        while (true) {
            cout << prompt;
            cin >> num1;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Enter a Real Number Please. \n";
            } else {
                break;
            }

        }
        return num1;
    }

    /*Integer Checker Module ^*/
    // Checks if the User typed a real number.

int main() {

    char again;

    cout << "Two Number Calculator!" << endl;
    system("pause");
    double a = intChecker("Enter first number: ");
    cout << "What operation do you want to use?: ";
    cin >> op; opChecker(a, b);
    double b = intChecker("Enter second number: ");
    cout << fixed << setprecision(2) << "Result: " << opChecker(a,b) << endl;

    cout << "Calculate again? (y/n): " << flush;
    again = _getch();
    cout << again << endl;

    /*Re-calculate Prompt*/
    //Prompts the Users if they want to calculate two numbers again.

        if (again == 'n' || again == 'N') {
            cout << "Clean up terminal before exiting? (y/n): " << flush;
            char cleanup = _getch();
            cout << cleanup << endl;
            if (cleanup == 'y' || cleanup == 'Y') {
            system("cls");
            cout << "There! All clean~";
            }
        }

    /*Clean-up Prompt*/
    //Prompts the Users if they want the terminal wiped, before exiting.

        while (again == 'y' || again == 'Y') {
            double a = intChecker("Enter first number: ");
            cout << "What operation do you want to use?: ";
            cin >> op; opChecker(a, b);
            double b = intChecker("Enter second number: ");
            cout << fixed << setprecision(2) << "Result: " << opChecker(a,b) << endl;
            cout << "Calculate again? (y/n): " << flush;
            again = _getch();
            cout << again << endl;

            if (again == 'n' || again == 'N') {
            cout << "Clean up terminal before exiting? (y/n): " << flush;
            char cleanup = _getch();
            cout << cleanup << endl;
            if (cleanup == 'y' || cleanup == 'Y') {
            system("cls");
            cout << "There! All clean~";
            }

    /*Main UI Loop*/
    //Loops the Main UI duh.
        }
    }
    return 0;
}