#include <iostream>
#include <string>
using namespace std;

void controlPage() {
    cout << "3D TICTAC TOE!\n\n";

    cout << "Controls:\n"
         << "[S]Start | [X]Exit\n"
         << "[C]Clear Board\n"
         << "[P]Switch Planes\n"
         << "[A]Show all planes\n\n";

    cout << "To place a charcter, enter the:\n" 
         << "[plane], [row], and [column]\n"
         << "E.g. [1 2 3]\n";
}

void controlModule(char arr[][3][3], char move, bool &inGame, int &plane, char player) {
    char m = tolower(move);
    int x, y, z;

    if (m == 's') {
        cout << "Enter coords: ";
        cin >> z >> x >> y;

        arr[z - 1][x - 1][y - 1] = player;

    } else if (m == 'x') {
        cout << "Program Exited.\n";
        inGame = false;
    } else if (m == 'c') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    arr[i][j][k] = '.';
                }
            }
        }
        cout << "Board cleared.\n";
    } else if (m == 'p') {
        int temp;
        do {
            cout << "Select plane: ";
            cin >> temp;
            
        } while (temp < 1 || temp > 3);
        plane = temp - 1;
    } else if (m == 'a') {
        cout << "Planes 1 - 3:\n";

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cout << arr[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}

void validateWinner(char arr[][3][3], bool &inGame) {
    


}

int main() {
    int x =3, y = 3, z = 3;
    int currentPlane = 0;
    char board[3][3][3];

    char dot = '.';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                board[i][j][k] = dot;
            }
        }
    }

    char move;
    char player = 'X';
    bool inGame = (move != 'x' || move != 'X');

    controlPage();

    do {
        cout << "Current state of board:\n";
        cout << "+---------------------------+\n";
        cout << "You're seeing plane #" << currentPlane + 1 << "\n";

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[currentPlane][i][j] << " ";
            }
            cout << endl;
        }
        cout << "+---------------------------+\n";

        cout << "What's your move?" 
             << "(" << player << ")" << ": ";
        cin >> move;

        controlModule(board, move, inGame, currentPlane, player);
        player = (player == 'X' ? 'O' : 'X');

        cout << "+---------------------------+\n\n";

        //validateWinner(board, inGame);
    } while (inGame);


    return 0;
}