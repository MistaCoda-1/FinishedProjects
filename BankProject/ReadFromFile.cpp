#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

struct ReadDatabase {

void getAccountData(string name, int identification) {
    ifstream database("BankProject/ReadFromFile.csv");
    if (!database) {
        cout << "ERROR: Unable to open/read file.\n";
        return;
    }

    bool userFound = false;
    bool idMatches = false;

    string line;
    while (getline(database, line)) {
        stringstream ss(line);
        string n, idStr;

        getline(ss, n, ',');
        getline(ss, idStr, ',');

        int id = stoi(idStr);

        if (n == name) {
            userFound = true;
            if (id == identification) {
                idMatches = true;
            }
            break;
        }
    }

    if (!userFound) {
        cout << "User does not exist.\n";
    }
    else if (!idMatches) {
        cout << "User found, but ID doesn't match.\n";
    }
    else {
        cout << "Proceed\n";
    }
    database.close();
}

};

int main() {
    ReadDatabase records;

    cout << "--| Read From File |--\n\n";

    string name;
    int id;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "--------------------------------|\n";


    records.getAccountData(name, id);

    return 0;
}