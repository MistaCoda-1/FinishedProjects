#include <iostream>
using namespace std;

int carFee(int time, bool member);
int motorFee(int time, bool member);
int truckFee(int time, bool member);

int main() {

    const char car = 'C', motorcycle = 'M', truck = 'T';

    char inputVehicle, hasMembership;
    int hoursParked;

    cout << "Parking Lot Fee System\n\n";
    cout << "Vehicle Type: ";
    cin >> inputVehicle;
    cout << "Hours parked: ";
    cin >> hoursParked;
    cout << "Membership: ";
    cin >> hasMembership;

    if (hasMembership == 'y' || hasMembership == 'Y') {
        hasMembership = true;
    } else {
        hasMembership = false;
    }

    //============

    cout << "\n=== Parking Ticket ===\n\n";

    if (inputVehicle == car) {
        cout << "Vehicle: Car\nHours Parked: " << hoursParked << "\nMembership Status: " << ((hasMembership)? "Active" : "Inactive");
        cout << "\nTotal Amount to pay: " << carFee(hoursParked, hasMembership) << endl;
    } else if (inputVehicle == motorcycle) {
        cout << "Vehicle: Motorcycle\nHours Parked: " << hoursParked << "\nMembership Status: " << ((hasMembership)? "Active" : "Inactive");
        cout << "\nTotal Amount to pay: " << motorFee(hoursParked, hasMembership) << endl;
    } else if (inputVehicle == truck) {
        cout << "Vehicle: Truck\nHours Parked: " << hoursParked << "\nMembership Status: " << ((hasMembership)? "Active" : "Inactive");
        cout << "\nTotal Amount to pay: " << truckFee(hoursParked, hasMembership) << endl;
    } else {
        cout << "Invalid information.";
    }

    return 0;
}

int carFee(int time, bool member) {
    int baseCost = 50, additionalCost = 0;

    if (time == 2) {
        return baseCost;
    } else {
        for (int i = 2; i <= time; i++) {
            additionalCost += 20;
        }

        int totalCost = baseCost + additionalCost;

        if (member && totalCost < 500) {
            return totalCost - 50;
        } else if (member && totalCost > 500) {
            int discount = totalCost * 0.10;
            return totalCost - discount;
        } else {
            return totalCost;
        }
    }
}

int motorFee(int time, bool member) {
    int baseCost = 30, additionalCost = 0;

    if (time == 2) {
        return baseCost;
    } else {
        for (int i = 2; i <= time; i++) {
            additionalCost += 10;
        }

        int totalCost = baseCost + additionalCost;

        if (member && totalCost < 500) {
            return totalCost - 50;
        } else if (member && totalCost > 500) {
            int discount = totalCost * 0.10;
            return totalCost - discount;
        } else {
            return totalCost;
        }
    }
}

int truckFee(int time, bool member) {
    int baseCost = 100, additionalCost = 0;

    if (time == 2) {
        return baseCost;
    } else {
        for (int i = 2; i <= time; i++) {
            additionalCost += 50;
        }

        int totalCost = baseCost + additionalCost;

        if (member && totalCost < 500) {
            return totalCost - 50;
        } else if (member && totalCost > 500) {
            int discount = totalCost * 0.10;
            return totalCost - discount;
        } else {
            return totalCost;
        }
    }
}