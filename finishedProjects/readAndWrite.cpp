#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct User {
    string username;
    string password;
};

// Simulate reading users from file (not actual JSON parsing, just placeholder)
vector<User> readUsersFromFile(const string& filename) {
    vector<User> users;
    ifstream inFile(filename);
    string line;

    User temp;
    while (getline(inFile, line)) {
        if (line.find("\"username\"") != string::npos) {
            size_t start = line.find(": \"") + 3;
            size_t end = line.rfind("\"");
            temp.username = line.substr(start, end - start);
        }
        if (line.find("\"password\"") != string::npos) {
            size_t start = line.find(": \"") + 3;
            size_t end = line.rfind("\"");
            temp.password = line.substr(start, end - start);
            users.push_back(temp);  // Push once both fields are filled
        }
    }
    return users;
}

void writeUsersToFile(const vector<User>& users, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "{\n  \"users\": [\n";
        for (size_t i = 0; i < users.size(); ++i) {
            const User& u = users[i];
            outFile << "    {\n";
            outFile << "      \"username\": \"" << u.username << "\",\n";
            outFile << "      \"password\": \"" << u.password << "\"\n";
            outFile << "    }" << (i < users.size() - 1 ? "," : "") << "\n";
        }
        outFile << "  ]\n}";
    }
}

int main() {
    const string filename = "readAndWrite.txt";
    vector<User> users = readUsersFromFile(filename);

    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;

    users.push_back(newUser);
    writeUsersToFile(users, filename);

    cout << "User saved successfully!\n";
    return 0;
}
