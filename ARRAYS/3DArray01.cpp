#include <iostream>
#include <string>
using namespace std;

void initBoard(char board[][3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                board[i][j][k] = '?';
            }
        }
    }
}

void showBoard(char board[][3][3], int n) {
    cout << "//==========//\n";
    cout << "+ - - - +\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "|";
            for (int k = 0; k < n; k++) {
                cout << " " << board[i][j][k];
            }
            cout << " |\n";
        }
        cout << "+ - - - +\n";
    }
    cout << "//==========//\n";
}

void displayPlane(char board[][3][3], int n, int currentPlane) {
    cout << "+ - - - +\n";
    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout << " " << board[currentPlane][i][j];
        }
        cout << " |\n";
    }
    cout << "+ - - - +\n";
}

void placeChar(char board[][3][3], char action, char player, bool &inGame) {
    int z, x, y;
    if (action == 'x') {
        cout << "Program Exited.\n";
        inGame = false;
    } else if (action == 'p') {
        cout << "Enter coords: ";
        cin >> z >> x >> y;

        if (z < 0 || x < 0 || y < 0) {
            cout << "Invalid coordinates!\n";
        } else if (z > 3 || x > 3 || y > 3) {
            cout << "Invalid coordinates!\n";
        }

        board[z - 1][x - 1][y - 1] = player;
    } else {
        cout << "Invalid Move.\n";
        cin >> action;
    }
}

void switchPlane(int &p) {
    int temp;
    cout << "Which plane do you want to display?: ";
    cin >> temp;
    p = temp - 1;
}

bool checkLine(char board[][3][3], int x, int y, int z,
               int dx, int dy, int dz) {
    char first = board[x][y][z];
    if (first == '?') return false;

    for (int step = 1; step < 3; step++) {
        int nx = x + dx * step;
        int ny = y + dy * step;
        int nz = z + dz * step;

        if (board[nx][ny][nz] != first) return false;
    }
    cout << first << " Wins!\n";
    return true;
}

    bool validateWinner(char board[][3][3]) {
        int dirs[13][3] = {
            {1,0,0}, {0,1,0}, {0,0,1},      
            {1,1,0}, {1,0,1}, {0,1,1},      
            {1,1,1},                        
            {1,1,-1}, {1,-1,1}, {1,-1,-1},  
            {0,1,-1}, {1,0,-1}, {0,-1,1}    
        };

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {

                    for (auto &d : dirs) {
                        int dx = d[0], dy = d[1], dz = d[2];

                        int endX = x + dx * 2;
                        int endY = y + dy * 2;
                        int endZ = z + dz * 2;

                        if (endX < 0 || endX >= 3 ||
                            endY < 0 || endY >= 3 ||
                            endZ < 0 || endZ >= 3)
                            continue;

                        if (checkLine(board, x, y, z, dx, dy, dz))
                            return true;
                    }
                }
            }
        }
        return false;
    }

int main() {

    char board[3][3][3];
    int n = 3;
    char player = 'X';
    int currentPlane = 0;
    char action;
    bool inGame = true;

    initBoard(board, n);
    
    cout << "Controls:\n"
         << "[P]Place Character\n"
         << "[A]Show All Planes\n"
         << "[S]Switch Plane\n"
         << "[X]Exit Program\n\n";

    do {
        cout << "Displaying [Plane #" << currentPlane + 1 << "]\n";
        displayPlane(board, n, currentPlane);
    
        cout << "What's your move?(" << player << "): ";
        cin >> action;
    
        action = tolower(action);

        if (action == 'a') {
            showBoard(board, n);
            continue;
        } else if (action == 's') {
            switchPlane(currentPlane);
            continue;
        } else {
            placeChar(board, action, player, inGame);
                if (validateWinner(board)) {
                inGame = false;
                break;
            }
        }

        player = (player == 'X' ? 'O' : 'X');

    } while (inGame);


    return 0;
}
