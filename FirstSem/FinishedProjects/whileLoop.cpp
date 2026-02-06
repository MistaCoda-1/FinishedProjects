#include <iostream>
#include <string>
using namespace std;

void whileLoop(char &admin, int &attempts, int &reallyCounter) {
    if (admin == 'N') {
        cout << "Well then get out of here!\n";
    } else {
        while (admin == 'Y') {
    
            string question = "Are you ";
            system("cls");
            for (int i = 0; i < reallyCounter; i++) {
                question += "really ";
                system("cls");
            }
            question += "sure you're the admin?: ";
            
            cout << question;
            cin >> admin;
    
            attempts += 1;
            reallyCounter += 1;
    
            if (admin == 'N') {
                system("cls");
                cout << "Aha! I knew it! Now get out of here!\n";
            } else if (attempts >= 3) {
                system("cls");
                cout << "I'm still not convinced but... You can go now.\n";
                break;
            }
        }
    }
}

int main() {

    char admin;
    int attempts = 0, reallyCounter = 0;

    cout << "Are you the admin? (Y/N): ";
    cin >> admin;

    whileLoop(admin, attempts, reallyCounter);
    
    return 0;
}