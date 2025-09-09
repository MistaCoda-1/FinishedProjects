#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

double readNumber() {
    string input;
    cin >> input;

    input.erase(remove(input.begin(), input.end(), ','), input.end());

    return stod(input);
}

int main() {

    double buyValue, sellValue, amountToInvest;
    double cryptoOwned, overallProfit, percentChange, finalValue;

    cout << "Crypto Flipper Simulator\n\n";

    cout << "Amount to Invest: ";
    amountToInvest = readNumber();

    cout << "Enter Buy Value: ";
    buyValue = readNumber();

    cout << "Enter Sell Value: ";
    sellValue = readNumber();

    //==============
    // CALCULATIONS
    //==============

    cryptoOwned = amountToInvest / buyValue;
    finalValue = cryptoOwned * sellValue;
    overallProfit = finalValue - amountToInvest;
    percentChange = ((sellValue - buyValue) / buyValue) * 100;

    
    cout << "\n=== [Calculations] ===\n";
    cout << "Crypto owned: " << cryptoOwned << endl;
    cout << fixed << setprecision(2);
    cout << "Final Value:  ₱" << finalValue << endl;
    cout << "Total profits: ₱" << overallProfit << endl;
    cout << "Percentage of buy/sell = " << percentChange << "%"<< endl;
    
    return 0;
}