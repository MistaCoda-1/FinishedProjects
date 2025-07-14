#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int main() {

    double a;
    double b;
    double result;
    char op;

    cout << "Two Number Calculator!" << endl;
    system("pause");
    cout << "Enter first number: ";
    cin >> a;
    cout << "What operation do you want to use?: ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;


    if (op == '+') {
        result = a+b;
    } else if (op == '-') {
        result = a-b;
    } else if (op == '*') {
        result = a*b;
    } else if (op == '/') {
        result = a/b;
    } else {
        cout << "Do you not know what an operator is?" << endl;
        Sleep(2000);
        exit(0);
        //Exit terminal after a few seconds.
    }

    cout << fixed << setprecision(2) << "Result: " << result;
    return 0;
}
