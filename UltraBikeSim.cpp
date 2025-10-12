#include <iostream>
using namespace std;

struct Bike {

    string name;
    int speed = 0;
    int maxSpeed;
    int fuel;
    int accelRate;
    int decelRate;

    void showDeets() {
        cout << "\nYou chose the [ " << name << " ] as your bike!\n\n";
        cout << "Max Speed: " << maxSpeed << endl;
        cout << "Fuel Tank: " << fuel << endl;
        cout << "Acceleration Rate: " << accelRate << endl;
        cout << "Deceleration Rate: " << decelRate << endl;
    }

    void accelerate() {
        if (fuel <= 0) {
            cout << "\nOut of fuel! You can't accelerate.\n";
            return;
        }

        if (speed + accelRate <= maxSpeed) {
            speed += accelRate;
            fuel -= 2;
            cout << "\n[" << name << "] Speed: " << speed << " km/h | Fuel: " << fuel << "\n\n";
        } else {
            speed = maxSpeed;
            fuel -= 2;
            cout << "\n[" << name << "] You're already at top speed (" << maxSpeed << " km/h)!\n\n";
        }
    }

    void decelerate() {
        if (speed - decelRate >= 0) {
            speed -= decelRate;
        } else {
            speed = 0;
        }
        cout << "\n[" << name << "] Speed: " << speed << " km/h | Fuel: " << fuel << endl;
    }

};

void showDest(int dist, string place);

int main() {

    Bike Ninja400 = {"Kawasaki Ninja 400", 0, 190, 200, 15, 10};
    Bike Ninja650 = {"Kawasaki Ninja 650", 0, 260, 200, 25, 15};
    Bike NinjaZX25R = {"Kawasaki Ninja ZX-25R", 0, 300, 250, 30, 15};
    Bike NinjaZX10 = {"Kawasaki Ninja ZX-10", 0, 350, 250, 35, 15};

    int bikeOpt;
    Bike* currentBike = nullptr;

    cout << "Ultra Realistic Bike Simulator!\n\n";

    do {
        cout << "1. Kawasaki Ninja 400\n";
        cout << "2. Kawasaki Ninja 650\n";
        cout << "3. Kawasaki Ninja ZX-25R\n";
        cout << "4. Kawasaki Ninja ZX-10R\n";
        cout << "Chose your bike: ";
        cin >> bikeOpt;
    
        switch (bikeOpt) {
            case 1:
            currentBike = &Ninja400;
            break;
            case 2:
            currentBike = &Ninja650;
            break;
            case 3:
            currentBike = &NinjaZX25R;
            break;
            case 4:
            currentBike = &NinjaZX10;
            break;
            default: 
            cout << "\nPlease choose a bike from the options!\n\n";
        }
    } while (bikeOpt >= 5);

    currentBike->showDeets();

    int dest, dstnc;
    string place;

    do {
        cout << "\nWhere are you heading?\n";
        cout << "1. Imus (4km)\n";
        cout << "2. Bacoor (3km)\n";
        cout << "3. Tagaytay (6km)\n";
        cout << "4. Manila (9km)\n";
        cout << "Choose your destination: ";
        cin >> dest;
    
        switch (dest) {
            case 1:
            dstnc = 4000;
            place = "Imus";
            break;
            case 2:
            dstnc = 3000;
            place = "Bacoor";
            break;
            case 3:
            dstnc = 6000;
            place = "Tagaytay";
            break;
            case 4:
            dstnc = 9000;
            place = "Manila";
            break;
            default:
            cout << "\nPlease choose a destination from the options!\n\n";
        }
    } while (dest >= 5);

    showDest(dstnc, place);
    cout << "[ Journey started! ]\n\n";

    int bikeControl;

    do {
        cout << "Press [ 1 ] to Accelerate\n";
        cout << "Press [ 2 ] to Decelerate\n";
        cout << "Press [ 3 ] to Check Map\n";
        cout << "Press [ 4 ] to Check Fuel Gauge\n";
        cout << "Choose action: ";
        cin >> bikeControl;

        switch (bikeControl) {
            case 1:
            currentBike->accelerate();
            dstnc -= currentBike->speed;
            break;
            case 2:
            currentBike->decelerate();
            break;
            case 3:
            showDest(dstnc, place);
            break;
            case 4:
            cout << "\nYou have [ "<< currentBike->fuel << " ] fuel left!\n\n";
            break;
            default:
            cout << "\nChoose a proper action to execute!\n\n";
        }

    } while (dstnc > 0);

    if (dstnc <= 0) {
        cout << "Destination Reached!\n\n";
    }

    return 0;
}

void showDest(int dist, string place) {
    cout << "\nHeading to [ " << place << " ] City!\n";
    cout << "Distance: " << dist << " meters\n\n";
}