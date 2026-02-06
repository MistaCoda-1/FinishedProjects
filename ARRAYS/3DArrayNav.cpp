#include <iostream>
#include <string>
using namespace std;

const int boundary = 5;

void showLayer(int x, int y, int z) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == x && j == y) {
                cout << "P ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void moveChar(char c, int &x, int&y, int &z) {
    if (c == 'n' || c == 'N') {
        x--;
    } else if (c == 'e' || c == 'E') {
        y++;
    } else if (c == 's' || c == 'S') {
        x++;
    } else if (c == 'w' || c == 'W') {
        y--;
    } else if (c == 'u' || c == 'U') {
        z++;
    } else if (c == 'd' || c == 'D') {
        z--;
    } else if (c == 'x' || c == 'X') {
        cout << "Program Exited.\n";
    } else {
        cout << "Invalid Action.\n";
    }
}

int main() {
    int x = 0, y = 0, z = 0;
    char move;

    cout << "== 3D PLANE NAVIGATOR ==\n";
    cout << "Movement: N E S W / UP[U] DOWN[D]\n" 
         << "Controls: Exit[X]\n\n";

    do {
        if (x < 0) {
            x++;
        } else if (x >= boundary) {
            x--;
        } else if (y < 0) {
            y++;
        } else if (y >= boundary) {
            y--;
        } else if (z < 0) {
            z++;
        } else if (z >= boundary) {
            z--;
        }

        cout << "You are currently at layer: " << z << endl
            << "[" << x << "]," << "[" << y << "]," << "[" << z << "]"  << endl;
        cout << "--------------------------------------------------|\n";
            showLayer(x, y, z);
        cout << "--------------------------------------------------|\n";
        cout << "Action: ";
        cin >> move;
        moveChar(move, x, y, z);
        if (move == 'x' || move == 'X') {
            break;
        }
        cout << endl;

    } while (true);

    return 0;
}