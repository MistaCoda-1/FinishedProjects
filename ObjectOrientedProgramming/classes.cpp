#include <iostream>
using namespace std;

struct Bike {
    int speed = 0;
    int minspeed = 0;
    int maxspeed = 100;
    int fuel = 10;

    void accelerate() {
        if (fuel <= 0) {
            cout << "\nYou're out of fuel!\n";
            return;
        }

        if (speed >= maxspeed) {
            cout << "\nSlow down, you're going too fast!\n";
            return;
        }

        speed += 10;
        fuel -= 3;
        cout << "\nThe bike is now going " << speed << " km/h!\n";
        cout << "Fuel gauge: " << fuel << endl;
    }

    void decelerate() {
        if (speed > minspeed) {
            speed -= 5;
            cout << "\nThe bike is now going " << speed << " km/h!\n";
            cout << "Fuel gauge: " << fuel << endl;
        } else {
            cout << "\nYou can't get any slower than not moving.\n";
            cout << "Fuel gauge: " << fuel << endl;
        }
    }
    
};

int main() {

    int choice;
    Bike ninja400;

    cout << "Bike simulator or something.";

    do {
        cout << "\nPress [ 1 ] to accelerate\n";
        cout << "Press [ 2 ] to decelerate\n";
        cout << "Press [ 3 ] to kill engine\n";

        cout << "Enter choice here: ";
        cin >> choice;
    
        if (choice == 1) {
            ninja400.accelerate();
        } else if (choice == 2) {
            ninja400.decelerate();
        } else {
            cout << "\nThe bike stalled.\n";
        }
    } while (choice != 3 && ninja400.fuel > 0);

    return 0;
}
