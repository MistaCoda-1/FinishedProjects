#include <iostream>
using namespace std;

void collatzSequence(int n);

int main() {
    int n;

    cout << "=== [Collatz Sequence Explorer]  ===\n\n";
    cout << "Enter a Number: ";
    cin >> n;

    collatzSequence(n);

    return 0;
}

void collatzSequence(int n) {
    if (n <= 0) {
        cout << "Invalid Input! Pick a number greater than 0!\n";
        return;
    }

    int m = n;
    int steps = 0;

    cout << "Sequence: " << n << " ";

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        cout << n << " ";

        if (n > m) {
            m = n;
        }
        steps++;
    }

    cout << "\nSteps: " << steps;
    cout << "\nLargest Number: " << m << endl;
}
