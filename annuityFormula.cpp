#include <iostream>
#include <cmath>
#include <iomanip>
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

double simulateFutureValue(double P, double d, double annualRate, int compPerYear, int depPerYear, double years) {
    double balance = P;
    double ratePerPeriod = annualRate / compPerYear;
    int totalPeriods = compPerYear * years;

    for (int i = 1; i <= totalPeriods; i++) {
        balance *= (1 + ratePerPeriod);

        if (i % (compPerYear / depPerYear) == 0) {
            balance += d;
        }
    }

    return balance;
}

int main() {
    double initialDep, rateDep, years;
    double annualRate = 0.15;
    int compPeriod, depPeriod;

    cout << "Annuity Formula Calculator\n\n";

    cout << "Compounding frequency per year: ";
    cin >> compPeriod;

    cout << "Deposit frequency per year: ";
    cin >> depPeriod;

    cout << "Deposit amount each time: ";
    cin >> rateDep;

    cout << "Initial deposit: ";
    cin >> initialDep;

    cout << "Number of years: ";
    cin >> years;

    double finalAmount = simulateFutureValue(initialDep, rateDep, annualRate, compPeriod, depPeriod, years);

    system("cls");

    cout << fixed << setprecision(2);
    cout << "\t=== RECEIPT ===\n\n";
    cout << "Compounded: " << timePeriod(compPeriod) << " (" << compPeriod << "x/year)\n";
    cout << "Deposited every: " << depPeriod << " times per year\n";
    cout << "Deposit amount: " << rateDep << "\n";
    cout << "Initial deposit: " << initialDep << "\n";
    cout << "Account years: " << years << "\n";

    cout << "\nFinal amount after " << years << " years: " << finalAmount << endl;

    return 0;
}
