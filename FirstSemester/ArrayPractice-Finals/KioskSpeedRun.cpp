#include<iostream>
#include<string>
using namespace std;

void displayInputs(int orders[][5][3], int prices[], string items[]) {
    int n = 5;
    cout << "== KIOSK SIMULATOR 9000 ==\n\n";
    for (int i = 0; i < n; i++) {

        cout << "Good morning, customer #" << i + 1 << "!\n";
        for (int j = 0; j < n; j++) {
            cout << "\nOrder #" << j + 1 << " Details:\n";
            for (int k = 0; k < n; k++) {
                cout << k + 1 << " - " << items[k] << " P" << prices[k] << endl;
            }
            int ID, qty;
            bool validInput;

            do {
                cout << "Enter item ID: ";
                cin >> ID;

                if (ID < 1 || ID > n) {
                    cout << "ERROR! Invalid Input!\n";
                    validInput = false;
                } else {
                    validInput = true;
                }
            } while(!validInput);
            cout << "Enter amount to buy: ";
            cin >> qty;

            int totalPrice = prices[ID - 1] * qty;

            orders[i][j][0] = ID;
            orders[i][j][1] = qty;
            orders[i][j][2] = totalPrice;
        }
        cout << "\n//==============================================//\n\n";
    }
}

void displayReceipts(int orders[][5][3], int prices[], string items[]) {
    int n = 5;
    cout << "== CUSTOMER RECEIPTS ==\n\n";
    for (int i = 0; i < n; i++) {
        cout << "Customer #" << i + 1 << " Receipt:\n";
        int grandTotal = 0;
        for (int j = 0; j < n; j++) {
            int ID = orders[i][j][0];
            int qty = orders[i][j][1];
            int total = orders[i][j][2];

            cout << " -" << items[ID - 1] << " x" << qty << " =\tP" << total << endl;
            grandTotal += total;
        }
        cout << "Total Amount To Pay: " << grandTotal;
        cout << "\n\n//==============================================//\n\n";
    }

}

int main() {

    int orders[5][5][3];
    int prices[5] = { 15, 79, 59, 20, 20 };
    string items[5] = { "Chips", "Fries", "Burger", "Coke", "Sprite" };

    displayInputs(orders, prices, items);
    displayReceipts(orders, prices, items);
    
    return 0;
}