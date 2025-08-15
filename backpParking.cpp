#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

int calcFee(int hours, int baseFee, int rates);
int discount(int total, bool member);

int main() {

    char vehicleInput, membershipInput, overnightInput;
    int hoursParkedInput, baseFee, rates;
    int surCharge = 0, totalCost = 0;
    string vehicle, weekDay;
    bool hasMembership, overnight;
    
    cout << "Parking Lot Fee! V2!\n\n";

    cout << "Vehicle: ";
    cin >> vehicleInput;

    switch (vehicleInput) {
        case 'C':
            vehicle = "CAR";
            baseFee = 50;
            rates = 20;
            break;
        case 'M':
            vehicle = "MOTORCYCLE";
            baseFee = 30;
            rates = 10;
            break;
        case 'T':
            vehicle = "TRUCK";
            baseFee = 100;
            rates = 50;
            break; 
        default:
            system("cls");
            cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
            Sleep(3000);
            exit(0);
    }

    cout << "Hours Parked: ";
    cin >> hoursParkedInput;

    if (hoursParkedInput <= 0) {
            system("cls");
            cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
            Sleep(3000);
            exit(0);
    } else if (hoursParkedInput >= 300) {
            system("cls");
            cout << "Buy your own garage bruh.\n\nExiting in 3 seconds. . .";
            Sleep(3000);
            exit(0);
    }

    cout << "Membership: ";
    cin >> membershipInput;

    if (membershipInput == 'y' || membershipInput == 'Y') {
        hasMembership = true;
    } else if (membershipInput == 'n' || membershipInput == 'N') {
        hasMembership = false;
    } else {
        system("cls");
        cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
        Sleep(3000);
        exit(0);
    }

    cout << "Day of the week: ";
    cin.ignore();
    getline(cin, weekDay);

    transform(weekDay.begin(), weekDay.end(), weekDay.begin(), :: toupper);

    if (weekDay == "SUNDAY" || weekDay == "SATURDAY") {
        surCharge = 20;
    }

    cout << "Overnight: ";
    cin >> overnightInput;

    if (overnightInput == 'y' || overnightInput == 'Y') {
        overnight = true;
    } else if (overnightInput == 'n' || overnightInput == 'N') {
        overnight = false;
    } else {
        system("cls");
        cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
        Sleep(3000);
        exit(0);
    }

    totalCost = calcFee(hoursParkedInput, baseFee, rates);

    int dc = discount(totalCost, hasMembership);
    totalCost = (totalCost + surCharge) - dc;

    if (overnight) {
        totalCost += 100;
    }

    cout << "\n=== PARKING TICKET ===\n\n";

    cout << "Vehicle: \t" << vehicle << endl;
    cout << "Hours Parked: \t" << hoursParkedInput << endl;
    cout << "Membership: \t" << ((hasMembership)? "Active" : "Inactive") << endl;
    cout << "Day: \t\t" << weekDay << endl;
    cout << "Overnight: \t" << ((overnight)? "Yes" : "No") << endl;
    cout << "Base Fee: \t" << baseFee << endl;
    cout << "Surcharge: \t" << surCharge << endl;
    cout << "Discount: \t" << dc << endl;
    cout << "Total to Pay: \t" << totalCost << endl;

    return 0;
}

int calcFee(int hours, int baseFee, int rates) {
    int totalCost = 0;

    if (hours <= 2) {
        return baseFee;
    } else {
        int hourlyRate = 0;
        for (int i = 2; i < hours; i++) {
            hourlyRate += rates;
        }
        return baseFee + hourlyRate;
    }
}

int discount(int total, bool member) {
    if (member) {
        int dc = total * 0.10;
        if (dc >= 50) {
            dc = 50;
        } else {
            return dc;
        }
    } else {
        return 0;
    }
}