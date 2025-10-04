#include <iostream>
using namespace std;

double calcXY(double x, double y, int op);

int main() {

    double operand, x, y, result;
    char retry;

    do {
        cout << "-- Basic Calculator --\n";

        cout << "1. Addition\n";
        cout << "1. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";

        cout << "Choose an operation to use: ";
        cin >> operand;

        if (operand > 4) {
            cout << "\nERROR! Invalid Input!\n";
            break;
        }

        cout << "Enter the first number: ";
        cin >> x;
        cout << "Enter the second number: ";
        cin >> y;

        result = calcXY(x, y, operand);

        cout << "Result: " << result << endl;

        cout << "Do you want to calculate again? (y/n): ";
        cin >> retry;

        cout << endl;

    } while (retry == 'y' || retry == 'Y');

    if (retry == 'n' || retry == 'N') {
        cout << "Calculator Exited. Thank you!\n";
    } else {
        cout << "ERROR! Invalid Input\n";
    }

    return 0;
}

double calcXY(double x, double y, int op) {

    if (op == 1) {
        return x + y;
    } else if (op == 2) {
        return x - y;
    } else if (op == 3) {
        return x * y;
    } else {
        if (x == 0 || y == 0) {
            cout << "\nERROR! Cannot Divide By Zero!\n";
            return 0;
        } else {
            return x / y;
        }
    }

}