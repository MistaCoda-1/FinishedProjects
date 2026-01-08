#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Helper functions
void isOn(bool v) {
    if (v) cout << "ON\n";
    else cout << "OFF\n";
}

bool isTrue(int v) {
    if (v == 1) return true;
    else if (v == 0) return false;
    else {
        cout << "Invalid input! Using OFF by default.\n";
        return false;
    }
}

// -------------------- OPTIONS --------------------
class Options {
private:
    bool ray_tracing;
    bool v_sync;
    int h, w;

public:
    Options() : ray_tracing(false), v_sync(false), h(1920), w(1080) {}

    void display() const {
        cout << "Graphics Options:\n";
        cout << "Ray Tracing: "; isOn(ray_tracing);
        cout << "VSync: "; isOn(v_sync);
        cout << "Resolution: " << h << "x" << w << "\n";
    }

    void toggleRayTracing(int val) { ray_tracing = isTrue(val); }
    void toggleVSync(int val) { v_sync = isTrue(val); }

    void changeResolution(int newH, int newW) {
        h = newH;
        w = newW;
    }
};

// -------------------- CONTROLS --------------------
class Controls {
private:
    vector<char> keys; // forward, left, back, right
public:
    Controls() {
        keys = {'w','a','s','d'};
    }

    void display() const {
        cout << "Controls:\n";
        cout << "Forward: " << keys[0] << "\n";
        cout << "Left:    " << keys[1] << "\n";
        cout << "Back:    " << keys[2] << "\n";
        cout << "Right:   " << keys[3] << "\n";
    }

    void changeKey(char current, char newKey) {
        for (char &c : keys) {
            if (c == current) {
                c = newKey;
                cout << "Key changed successfully!\n";
                return;
            }
        }
        cout << "Key not found!\n";
    }
};

// -------------------- SOUNDS --------------------
class Sounds {
private:
    bool music;
    int musicVol;
    bool sound;
    int soundVol;
public:
    Sounds() : music(true), musicVol(100), sound(true), soundVol(100) {}

    void display() const {
        cout << "Audio Options:\n";
        cout << "Music: "; isOn(music);
        if (music) cout << "Music Volume: " << musicVol << "\n";
        cout << "Sound: "; isOn(sound);
        if (sound) cout << "Sound Volume: " << soundVol << "\n";
    }

    void toggleMusic(int val) { music = isTrue(val); }
    void toggleSound(int val) { sound = isTrue(val); }
    void setMusicVol(int val) { musicVol = val; }
    void setSoundVol(int val) { soundVol = val; }
};

// -------------------- MENU --------------------
class Menu {
private:
    Options options;
    Controls controls;
    Sounds sounds;

public:
    void displayAll() const {
        cout << "\n===== CURRENT SETTINGS =====\n";
        options.display();
        cout << endl;
        controls.display();
        cout << endl;
        sounds.display();
        cout << "============================\n\n";
    }

    void run() {
        int choice;
        char cont;

        do {
            cout << "===== MENU =====\n";
            cout << "[1] Graphics Options\n";
            cout << "[2] Controls\n";
            cout << "[3] Audio Options\n";
            cout << "[4] Display All Settings\n";
            cout << "[5] Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    int subChoice;
                    cout << "\n-- Graphics Menu --\n";
                    cout << "[1] Toggle Ray Tracing\n";
                    cout << "[2] Toggle VSync\n";
                    cout << "[3] Change Resolution\n";
                    cout << "[4] Back\n";
                    cout << "Choose: ";
                    cin >> subChoice;
                    if(subChoice == 1) {
                        int val;
                        cout << "Enter 1 for ON, 0 for OFF: ";
                        cin >> val;
                        options.toggleRayTracing(val);
                    } else if(subChoice == 2) {
                        int val;
                        cout << "Enter 1 for ON, 0 for OFF: ";
                        cin >> val;
                        options.toggleVSync(val);
                    } else if(subChoice == 3) {
                        int h, w;
                        cout << "Enter new height: "; cin >> h;
                        cout << "Enter new width: "; cin >> w;
                        options.changeResolution(h, w);
                    }
                    break;
                }
                case 2: {
                    cout << "\n-- Controls Menu --\n";
                    controls.display();
                    char cur, newKey;
                    cout << "Enter key to change: ";
                    cin >> cur;
                    cout << "Enter new key: ";
                    cin >> newKey;
                    controls.changeKey(cur, newKey);
                    break;
                }
                case 3: {
                    int subChoice;
                    cout << "\n-- Audio Menu --\n";
                    cout << "[1] Toggle Music\n";
                    cout << "[2] Toggle Sound\n";
                    cout << "[3] Change Music Volume\n";
                    cout << "[4] Change Sound Volume\n";
                    cout << "[5] Back\n";
                    cout << "Choose: ";
                    cin >> subChoice;
                    if(subChoice == 1) {
                        int val;
                        cout << "Enter 1 for ON, 0 for OFF: "; cin >> val;
                        sounds.toggleMusic(val);
                    } else if(subChoice == 2) {
                        int val;
                        cout << "Enter 1 for ON, 0 for OFF: "; cin >> val;
                        sounds.toggleSound(val);
                    } else if(subChoice == 3) {
                        int vol;
                        cout << "Enter Music Volume (0-100): "; cin >> vol;
                        sounds.setMusicVol(vol);
                    } else if(subChoice == 4) {
                        int vol;
                        cout << "Enter Sound Volume (0-100): "; cin >> vol;
                        sounds.setSoundVol(vol);
                    }
                    break;
                }
                case 4:
                    displayAll();
                    break;
                case 5:
                    cout << "Exiting menu...\n";
                    return;
                default:
                    cout << "Invalid choice!\n";
            }

            cout << "\nDo you want to continue in menu? (y/n): ";
            cin >> cont;
            cout << endl;
        } while(cont == 'y' || cont == 'Y');
    }
};

// -------------------- MAIN --------------------
int main() {
    cout << "==== GAME MENU SIMULATOR ====\n\n";

    Menu menu;
    menu.run();

    cout << "\nThanks for using the menu simulator!\n";
    return 0;
}
