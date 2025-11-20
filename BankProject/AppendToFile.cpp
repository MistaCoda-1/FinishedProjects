#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Users {
    private:
        string username;
        int id;
        int balance = 0;
    protected:
        int key = 914;
    public:
        Users() {
            username = "";
            id = 0000;
            balance = 0;
        }
        Users(string name, int identification) {
            username = name;
            id = identification;
            balance = 0;
        }

        void setName() {
            getline(cin, username);
        }
        void setId() {
            string temp;
            getline(cin, temp);
            try {
                id = stoi(temp);
            } catch (const exception& e) {
                cout << "Invalid ID entered. Defaulting to 0.\n";
                id = 0;
            }
        }
        string getName() {
            return username;
        }
        int getID() {
            return id;
        }
        int getBal() {
            return balance;
        }

        char encryptDecrypt(char c, int key) {
            return c ^ key;
        }

        void appendToFile(string name, int id, int bal) {
            ofstream database("AppendToFile.txt", ios::app);
            if (!database) {
                cout << "ERROR: Unable to open/find file.\n";
                return;
            }

            string lineOfText = 
                    name + "|" + to_string(id) 
                         + "|" + to_string(bal);

            string encryptedLine;
            for (unsigned char c : lineOfText) {
                encryptedLine += encryptDecrypt(c, key);
            }
            database << encryptedLine << "\n";

            database.close();
        }
        void showDatabase() {
            ifstream database("AppendToFile.txt");
            if (!database) {
                cout << "ERROR: Unable to read file.\n";
                return;
            }

            string lineToDecrypt;
            while(getline(database, lineToDecrypt)) {
                string decryptedLine;
                for (char c : lineToDecrypt) {
                    decryptedLine += encryptDecrypt(c, key);
                }

                cout << decryptedLine << "\n";
            }
        }
};

void registerUser(Users &user1) {
    cout << "Enter Name: ";
    user1.setName();
    cout << "Enter ID: ";
    user1.setId();

    string name = user1.getName();
    int id = user1.getID();
    int bal = user1.getBal();
    user1.appendToFile(name, id, bal);

    cout << "-------------------------|\n"
         << "Append to file Succesful\n"
         << "-------------------------|\n\n";

    char choice;
    cout << "Show database?(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') 
        user1.showDatabase();
}

int main() {
    Users user1;
    cout << "-- | Append to file | --\n\n";

    int action;
    cout << "1 - Show Database" << endl
         << "2 - Register Account" << endl
         << "Enter Choice: ";
    cin >> action;
    cin.ignore(9999, '\n');
    cout << "-------------------------|\n";

    if (action == 1) {
        user1.showDatabase();
    } else if (action == 2) {
        registerUser(user1);
    } else {
        cout << "ERROR: Invalid input.";
    }

    return 0;
}