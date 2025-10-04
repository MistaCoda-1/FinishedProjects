#include <iostream>
#include <cmath>
using namespace std;

string timePeriod(int compPeriod) {
    switch (compPeriod) {
        case 1:   return "Annually";
        case 4:   return "Quarterly";
        case 12:  return "Monthly";
        case 26:  return "Bi-weekly";
        case 52:  return "Weekly";
        case 365: return "Daily";
        default:  return "Custom";
    }
}


int main() {

    double compPeriod, initialDep, rateDep, timeDep, val1, val2, finalAmount;
    double annualRate = 0.035;

    cout << "Annuity Formula Calculator\n\n";

    cout << "Compound Periods: ";
    cin >> compPeriod;

    cout << "Deposit Rate: ";
    cin >> rateDep;

    cout << "Initial Deposit: ";
    cin >> initialDep;

    cout << "Time Deposit: ";
    cin >> timeDep;

    //==============
    // CALCULATIONS
    //==============

    val1 = initialDep * pow(1 + (annualRate / compPeriod), compPeriod * timeDep);
    val2 = (rateDep * ((pow(1 + (annualRate / compPeriod), compPeriod * timeDep) - 1) / (annualRate / compPeriod)));
    finalAmount = val1 + val2;

    system("cls");
    cout << "\t=== RECEIPT ===\n\n";
    cout << "Compund Periods: " << timePeriod(compPeriod) << endl;
    cout << "Deposit Rate: " << rateDep << endl;
    cout << "Initial Deposit: " << initialDep << endl;
    cout << "Account years: " << timeDep << endl;

    cout << "\nFinal amount after " << timeDep << " years: " << finalAmount << endl;

    return 0;
}