#include<iostream>
#include<string>
using namespace std;

class vehicle {
    public:
        string vehicleBrand = "Yamaha";
        string vehicleSpeed;
        string vehicleColor;

        vehicle () {
            vehicleSpeed = "";
            vehicleColor = "";
        }
        vehicle (string s, string c) {
            vehicleSpeed = s;
            vehicleColor = c;
        }

        void beepHorn() {
            cout << "BEEP!\n";
        }
};

class car: public vehicle {
    public:
        string model = "R15 V3";

        void showSpecs() {
            cout << "+ | S P E C S | +\n";
        }
        string showModel() {
            return model;
        }
        string showBrand() {
            return vehicleBrand;
        }
};

int main() {

    car myCar;
    char opt, carButton;

    cout << "+ | VEHICLE THINGY SIMULATOR | +\n\n";

    do {
        cout << "[Q] to beep car horn: ";
        cin >> carButton;

        if (carButton == 'q' || carButton == 'Q') {
            myCar.beepHorn();
        } else if (carButton == 'a' || carButton == 'A') {
            cout << myCar.showBrand() << " " << myCar.showModel() << endl;;
        } else {
            break;
        }
    } while (true);

    return 0;
}