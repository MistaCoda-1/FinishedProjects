#include <iostream>
#include <string>

using namespace std;

class vehicle {
protected:
    string vehicleBrand;
    int vehicleSpeed;
    string vehicleColor;

public:
    vehicle(string brand, int speed, string color)
        : vehicleBrand(brand), vehicleSpeed(speed), vehicleColor(color) {}

    void beepHorn() {
        cout << "BEEP!\n";
    }
};

class car : public vehicle {
private:
    string model;

public:
    car(string brand, int speed, string color, string modelName)
        : vehicle(brand, speed, color), model(modelName) {}

    void showSpecs() {
        cout << "+ | S P E C S | +\n";
        cout << "Brand: " << vehicleBrand << endl;
        cout << "Model: " << model << endl;
        cout << "Speed: " << vehicleSpeed << " km/h" << endl;
        cout << "Color: " << vehicleColor << endl;
    }

    string showModel() {
        return model;
    }

    string showBrand() {
        return vehicleBrand;
    }
};

int main() {
    car myCar("Yamaha", 120, "Red", "R15 V3");

    char carButton;

    cout << "+ | VEHICLE THINGY SIMULATOR | +\n\n";

    do {
        cout << "[Q] Beep horn | [A] Show car | Any other key to exit: ";
        cin >> carButton;

        if (carButton == 'q' || carButton == 'Q') {
            myCar.beepHorn();
        } 
        else if (carButton == 'a' || carButton == 'A') {
            myCar.showSpecs();
        } 
        else {
            break;
        }
    } while (true);

    return 0;
}
