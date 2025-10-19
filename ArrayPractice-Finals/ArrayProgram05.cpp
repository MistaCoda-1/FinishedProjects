#include <iostream>
using namespace std;

int main() {

    int numbers[10];
    int toSearch;

    cout << "== Index searcher ==\n\n";

    cout << "Enter 10 numbers to store!\n";

    for (int i = 0; i < 10; i++) {
        cout << "Enter number #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nNumbers stored!\n\n";

    cout << "Enter an integer to search!: ";
    cin >> toSearch;

    for (int i = 0; i < 10; i++) {
        if (numbers[i] == toSearch) {
            cout << "Match found! Number [" << toSearch << "] exists!\n";
            break;
        } else if (i == 9) {
            cout << "No matches found!\n";
        }
    }

    return 0;
}