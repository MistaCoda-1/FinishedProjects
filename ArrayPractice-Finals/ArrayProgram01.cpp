#include <iostream>
using namespace std;

int main() {

    int toSum[5];
    int sum = 0;

    cout << "== Sum Calculator ==\n\n";

    for (int i = 0; i < 5; i++) {
        cout << "Enter num " << i + 1 << ": ";
        cin >> toSum[i];
    }

    for (int i = 0; i < 5; i++) {
        sum += toSum[i];
    }

    cout << "\nThe sum of all numbers is: " << sum << endl;

    return 0;
}