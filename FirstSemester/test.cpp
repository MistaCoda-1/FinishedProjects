#include <iostream>
using namespace std;

double vat(int vatable) {
    int totalprice, vatprice;

    vatprice = vatable * 0.12;
    return vatprice + vatable;
}

void selectionsection(int orders[][5][2], double prices[], string items[]) {
    int menudec;
    
    for(int c = 0; c < 5; c++){

        cout << "-----------------------------------";

        cout << "\nCustomer #" << c + 1 << ":\n";
        
        for(int o = 0; o < 5; o++) {
            
            cout << "\nOrder #" << o + 1 << ":\n";

            for (int k = 0; k < 5; k++) {
                cout << "[" << k + 1 << "] " << items[k] << " - P" << prices[k] << endl;
            }

            cout << "Ano ang gusto mong i-order?: ";
            cin >> menudec;

            int priceOfItem = prices[menudec - 1];

            orders[c][o][0] = menudec;
            orders[c][o][1] = vat(priceOfItem);
        }
    }
}

void displayReceipt(int orders[][5][2], double prices[], string items[]) {

    cout << "\n-----------------------------------------\n";

    cout << "== Customer Receipts ==\n";

    for (int i = 0; i < 5; i++) {

        cout << "Customer #" << i  + 1 << " Receipt:\n";
        int totalTax = 0;
        int toPay = 0;
        for (int j = 0; j < 5; j++) {

            int item = orders[i][j][0];
            int vat = orders[i][j][1];
            int totalPrice = prices[item - 1];

            cout << " -" << items[item - 1] << " =\tP" << prices[item - 1] << endl;
            totalTax += vat;
            toPay += totalPrice;
        }
        cout << "Total: " << toPay << endl;
        cout << "VAT: " << totalTax << endl;
        cout << "Final amount: " << toPay + totalTax;

        cout << "\n--------------------------------------------\n";
    }
}

int main()
{
    int menudec, vatable, c, o, receipt();

    int orders[5][5][2];
    string items[5] = { "Kapeng maligamgam", "Water", "Chicken oil from Mang Inasal (1 cup)",
        "Egg Salad Sandwich", "Spaghetti Bolognese" };

    double prices[5] = { 50.00, 17.00, 34.00, 43.00, 65.00 };

    selectionsection(orders, prices, items);
    displayReceipt(orders, prices, items);

    return 0;
}