#include <iostream>
#include <string>
using namespace std;

struct Bike {
    string name;
    int speed = 0;        // km/h
    int maxSpeed;         // km/h
    int fuel;             // arbitrary fuel units
    int accelRate;        // km/h per accelerate action
    int decelRate;        // km/h per decelerate action
    int accelFuelCost;    // fuel cost for accelerate
    int cruiseFuelCost;   // fuel cost for one cruise tick

    void showDeets() {
        cout << "\nYou chose the [ " << name << " ]!\n";
        cout << "Max Speed: " << maxSpeed << " km/h\n";
        cout << "Fuel Tank: " << fuel << "\n";
        cout << "Acceleration Rate: " << accelRate << " km/h per press\n";
        cout << "Deceleration Rate: " << decelRate << " km/h per press\n\n";
    }

    void accelerate() {
        if (fuel < accelFuelCost) {
            cout << "\nNot enough fuel to accelerate.\n";
            return;
        }
        if (speed + accelRate <= maxSpeed) {
            speed += accelRate;
        } else {
            speed = maxSpeed;
        }
        fuel -= accelFuelCost;
        if (fuel < 0) fuel = 0;
        cout << "\n[" << name << "] Accelerated -> Speed: " << speed << " km/h | Fuel: " << fuel << "\n";
    }

    void decelerate() {
        if (speed - decelRate >= 0) speed -= decelRate;
        else speed = 0;
        cout << "\n[" << name << "] Decelerated -> Speed: " << speed << " km/h | Fuel: " << fuel << "\n";
    }

    // Cruise: you travel while losing a little speed (simulates coasting)
    void cruise() {
        if (speed == 0) {
            cout << "\nYou're not moving yet — start accelerating first.\n";
            return;
        }
        int cruiseDecel = decelRate / 2; // gentle slow down when cruising
        if (speed - cruiseDecel >= 0) speed -= cruiseDecel;
        else speed = 0;

        if (fuel >= cruiseFuelCost) fuel -= cruiseFuelCost;
        else fuel = 0;

        cout << "\n[" << name << "] Cruising -> Speed now: " << speed << " km/h | Fuel: " << fuel << "\n";
    }

    // Travel tick: convert speed (km/h) to meters per second and subtract from distance
    // Assumes 1 tick = 1 second.
    void travelTick(double &distanceMeters) {
        double metersPerSecond = (double)speed / 3.6; // km/h -> m/s
        if (metersPerSecond < 0) metersPerSecond = 0;
        distanceMeters -= metersPerSecond;
        if (distanceMeters < 0) distanceMeters = 0;
        cout << "Traveled " << (int)metersPerSecond << " m this tick. Remaining: "
             << (int)distanceMeters << " m.\n\n";
    }
};

void showDest(double distMeters, const string &place) {
    cout << "\nHeading to [ " << place << " ]\n";
    cout << "Distance remaining: " << (int)distMeters << " meters\n\n";
}

int main() {
    Bike Ninja400    = {"Kawasaki Ninja 400",    0, 190, 200, 15, 10, 2, 1};
    Bike Ninja650    = {"Kawasaki Ninja 650",    0, 260, 200, 25, 15, 3, 1};
    Bike NinjaZX25R  = {"Kawasaki Ninja ZX-25R", 0, 300, 250, 30, 15, 3, 1};
    Bike NinjaZX10   = {"Kawasaki Ninja ZX-10R", 0, 350, 250, 35, 15, 4, 1};

    Bike* currentBike = nullptr;
    int bikeOpt = 0;

    cout << "Ultra Realistic Bike Simulator!\n\n";

    while (currentBike == nullptr) {
        cout << "Choose your bike:\n";
        cout << "1. Kawasaki Ninja 400\n";
        cout << "2. Kawasaki Ninja 650\n";
        cout << "3. Kawasaki Ninja ZX-25R\n";
        cout << "4. Kawasaki Ninja ZX-10R\n";
        cout << "Enter choice: ";
        cin >> bikeOpt;

        switch (bikeOpt) {
            case 1: currentBike = &Ninja400; break;
            case 2: currentBike = &Ninja650; break;
            case 3: currentBike = &NinjaZX25R; break;
            case 4: currentBike = &NinjaZX10; break;
            default: cout << "Please choose a valid bike (1-4).\n\n";
        }
    }

    currentBike->showDeets();

    int dest = 0;
    double dstnc = 0.0; // in meters
    string place;

    while (dstnc == 0.0) {
        cout << "Where are you heading?\n";
        cout << "1. Imus (4 km)\n";
        cout << "2. Bacoor (3 km)\n";
        cout << "3. Tagaytay (6 km)\n";
        cout << "4. Manila (9 km)\n";
        cout << "Choose destination: ";
        cin >> dest;

        switch (dest) {
            case 1: dstnc = 4000; place = "Imus"; break;
            case 2: dstnc = 3000; place = "Bacoor"; break;
            case 3: dstnc = 6000; place = "Tagaytay"; break;
            case 4: dstnc = 9000; place = "Manila"; break;
            default: cout << "Please choose a valid destination (1-4).\n\n";
        }
    }

    cout << "\n[ Journey started! ]\n\n";

    int action = 0;
    bool engineOff = false;

    while (!engineOff && dstnc > 0 && currentBike->fuel > 0) {
        cout << "Actions:\n";
        cout << "1 - Accelerate\n";
        cout << "2 - Decelerate\n";
        cout << "3 - Cruise\n";
        cout << "4 - Check Map\n";
        cout << "5 - Check Fuel\n";
        cout << "6 - Kill Engine (stop)\n";
        cout << "Choose action: ";
        cin >> action;

        switch (action) {
            case 1:
                currentBike->accelerate();
                currentBike->travelTick(dstnc);
                break;
            case 2:
                currentBike->decelerate();
                currentBike->travelTick(dstnc);
                break;
            case 3:
                currentBike->cruise();
                currentBike->travelTick(dstnc);
                break;
            case 4:
                showDest(dstnc, place);
                break; // map check doesn't advance time
            case 5:
                cout << "\nFuel left: " << currentBike->fuel << "\n\n";
                break; // fuel check doesn't advance time
            case 6:
                cout << "\nEngine killed. Stopping journey.\n\n";
                engineOff = true;
                break;
            default:
                cout << "\nChoose a valid action.\n\n";
        }

        if (currentBike->fuel <= 0) {
            cout << "\nYou're out of fuel! You can coast until you stop, but cannot accelerate.\n\n";
        }

        if (dstnc <= 0) {
            cout << "Destination reached! Welcome to " << place << "!\n\n";
            break;
        }
    }

    if (dstnc > 0 && currentBike->fuel <= 0) {
        cout << "You ran out of fuel before reaching the destination. Distance left: " << (int)dstnc << " m.\n";
    }

    cout << "Session ended.\n";
    return 0;
}
