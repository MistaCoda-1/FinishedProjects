#include <iostream>
using namespace std;

int main() {

    int num1, num2, higherValue;

    cout << "`?` || 'Ternary' Operator practice\n" << "\nIs `num1` greater than `num2`?\n" << endl;
    cout << "Enter value for `num1` here: ";
    cin >> num1;
    cout << "Enter value for `num2` here: ";
    cin >> num2;
    cout << endl;

    //=======================
    // `?` || Ternary Syntax
    //=======================
    
    higherValue = (num1 > num2)? num1 : num2;

    if (higherValue == num1) {
        cout << higherValue << " is greater!\n";
    } else if (higherValue == num2) {
        cout << higherValue << " is greater!\n";
    } else {
        cout << "Both numbers are equal!\n";
    }

    char choice;

    cout << "Learn more about 'Ternary' operators? (y/n): ";
    cin >> choice;
    cout << endl;

    if (choice == 'y' || choice == 'Y') {
        cout << "Ternary operators work like this: " << endl;
        cout << "`condition ? expression_if_true : expression_if_false;`\n" << endl;
        cout << "in psuedo-code it would be: \n";
        cout << "is (condition) true or false? runThisCodeIfTrue : runThisCodeIfFalse" << endl;
    }

    return 0;
}

// IGNORE THIS MESSAGE