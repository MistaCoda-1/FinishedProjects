#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class User {
    private:
        string username;
        int id;
    public:
        User() {
            username = "";
            id = 0000;
        }
        User(string n, int i) {
            username = n;
            id = i;
        }

        void setName() {
            cout << "Enter Username: ";
            getline(cin, username);
        }
        void setId() {
            string temp;
            cout << "Enter ID: ";
            getline(cin, temp);
            id = stoi(temp);
        }
        string getName() {
            return username;
        }
        int getId() {
            return id;
        }
};

struct DataHandler {
    void appendToCsv(User &user) {
        string filename = "accounts.csv";
        ofstream data(filename, ios::app);
        if (!data) {
            cerr << "ERROR: Couldn't write to file.\n";
            return;
        }

        string n;
        int i = user.getId();
        
        for (char c : user.getName()) {
            n += tolower(c);
        }

        string toApp = "\"" + n +  + "\"" + "," + to_string(i);
        data << toApp << "\n";

        cout << "//==========================//\n"
             << "//==  REGISTER SUCCESFUL  ==//\n"
             << "//==========================//\n";
        
        data.close();
    }
    void readFromCsv() {
        string filename = "accounts.csv";
        ifstream data(filename);
        if (!data) {
            cerr << "ERROR: Couldn't write to file.\n";
            return;
        }
        cout << "---------------------------------------------|\n";
        string line;
        while(getline(data, line)) {
            cout << line << "\n";
        }
        cout << "---------------------------------------------|\n";

        data.close();
    }
    bool authorizeLogin(User &user) {
        string filename = "accounts.csv";
        ifstream data(filename);
        if (!data) {
            cerr << "ERROR: Failed to open " << filename
                 << " for authorization.\n";
            return false;   
        }

        string accountInfo;
        string username;
        string id;

        while(data.ignore(9999, '"')) {
            getline(data, username, '"');
            data.ignore(9999, ',');
            getline(data, id);
            
            if (!data.eof()) {
                cout << "Username: " << username << endl
                     << "ID: " << stoi(id) << endl;
            } else {
                break;
            }
        }

        data.close();
    }
};

int main() {
    User admin;
    DataHandler data;

    int choice;
    cout << "== Account Manager ==\n\n";

    cout << "[1] Register\n"
         << "[2] Log-in\n"
         << "[3] Show Database\n"
         << "Enter Choice: ";
    cin >> choice;
    cin.ignore(9999, '\n');

    if (choice == 1) {
        cout << "---------------------------------------------|\n";
        admin.setName();
        admin.setId();
        data.appendToCsv(admin);
        cout << "---------------------------------------------|\n";
    } else if (choice == 2) {
        cout << "---------------------------------------------|\n";
        data.authorizeLogin(admin);
        cout << "---------------------------------------------|\n";
    } else if (choice == 3) {
        data.readFromCsv();
    } else {

    }

    return 0;
}