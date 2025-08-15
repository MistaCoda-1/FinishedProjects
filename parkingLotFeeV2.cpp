#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

void vehicleCheck(char v, string& vehicle, int& base, int& rate);
void timeCheck(int& time);
void memCheck(char member, bool& isMember);
int calcFee(int hours, int baseFee, int rates);
int discount(int total, bool member);

int main() {

    char vehicleInput, memberInput, overnightInput;
    int hoursParkedInput, baseFee, rates;
    int surCharge = 0, totalCost = 0;
    string vehicle, weekDay;
    bool membership, overnight;
    
    cout << "Parking Lot Fee! V2!\n\n";

    cout << "Vehicle: ";
    cin >> vehicleInput;

    vehicleCheck(vehicleInput, vehicle, baseFee, rates);

    cout << "Hours Parked: ";
    cin >> hoursParkedInput;

    timeCheck(hoursParkedInput);

    cout << "Membership: ";
    cin >> memberInput;

    memCheck(memberInput, membership);
    
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

    cout << hoursParkedInput << " " << baseFee << " " << rates;

    totalCost = calcFee(hoursParkedInput, baseFee, rates);

    int dc = discount(totalCost, membership);
    totalCost = (totalCost + surCharge) - dc;

    if (overnight) {
        totalCost += 100;
    }

    cout << "\n=== PARKING TICKET ===\n\n";

    cout << "Vehicle: \t" << vehicle << endl;
    cout << "Hours Parked: \t" << hoursParkedInput << endl;
    cout << "Membership: \t" << ((membership)? "Active" : "Inactive") << endl;
    cout << "Day: \t\t" << weekDay << endl;
    cout << "Overnight: \t" << ((overnight)? "Yes" : "No") << endl;
    cout << "Base Fee: \t" << baseFee << endl;
    cout << "Surcharge: \t" << surCharge << endl;
    cout << "Discount: \t" << dc << endl;
    cout << "Total to Pay: \t" << totalCost << endl;

    return 0;
}

void vehicleCheck(char v, string& vehicle, int& base, int& rate) {
    char lower_v = static_cast<char>(tolower(v));
    
    switch (lower_v) {
        case 'c':
        vehicle = "CAR";
        base = 50;
        rate = 20;
        break;
        case 'm':
        vehicle = "MOTORCYCLE";
        base = 30;
        rate = 10;
        break;
        case 't':
        vehicle = "TRUCK";
        base = 100;
        rate = 50;
        break;
        default:
        system("cls");
        cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
        Sleep(3000);
        exit(0);
    }
}

void timeCheck(int& time) {
    if (time <= 0) {
            system("cls");
            cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
            Sleep(3000);
            exit(0);
    } else if (time >= 300) {
            system("cls");
            cout << "Buy your own garage bruh.\n\nExiting in 3 seconds. . .";
            Sleep(3000);
            exit(0);
    }
}

void memCheck(char member, bool& isMember) {
    char lower_m = static_cast<char>(tolower(member));

    switch (lower_m) {
        case 'y':
        isMember = true;
        break;
        case 'n':
        isMember = false;
        break;
        default:
        system("cls");
        cout << "Invalid Input!\n\nExiting in 3 seconds. . .";
        Sleep(3000);
        exit(0);
    }
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

