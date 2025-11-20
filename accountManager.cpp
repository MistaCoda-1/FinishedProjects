#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class User {
    protected:
        int key = 125;
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
            cout << "Enter Name: ";
            getline(cin, username);
        }
        void setId() {
            cout << "Enter ID: ";
            string temp;
            getline(cin, temp);
            id = stoi(temp);
        }
        string getName() const {
            return username;
        }
        int getId() const {
            return id;
        }
        int getKey() const {
            return key;
        }
};

struct DataHandler {

    char encryptDecrypt(unsigned char c, int key) {
        return c ^ key;
    }
    //==============================================================
    string base64Encode(const string& input) {
    static const char table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    string output;
    int val = 0, valb = -6;

    for (unsigned char c : input) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            output.push_back(table[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) output.push_back(table[((val << 8) >> (valb + 8)) & 0x3F]);
    while (output.size() % 4) output.push_back('=');

    return output;
    }

    string base64Decode(const string& input) {
        static const int table[256] = {
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,
            52,53,54,55,56,57,58,59,60,61,-1,-1,-1, 0,-1,-1,
            -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,
            15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,
            -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
            41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1
        };

        string output;
        int val = 0, valb = -8;

        for (unsigned char c : input) {
            if (table[c] == -1) break;
            val = (val << 6) + table[c];
            valb += 6;
            if (valb >= 0) {
                output.push_back((char)((val >> valb) & 0xFF));
                valb -= 8;
            }
        }

        return output;
    }
    //==============================================================
    void appendToCSV(User &user) {
        ofstream database("accountManager.csv", ios::app);
        if (!database) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        string name = user.getName();
        int i = user.getId();
        int k = user.getKey();
        
        string lineToEncrypt = name + "," + to_string(i);
        string lineToAppend;
        for (unsigned char c : lineToEncrypt) {
            lineToAppend += (char)encryptDecrypt(c, k);
        }
        string encode = base64Encode(lineToAppend);
        database << encode << endl;

        database.close();
    }

    void readFromCSV(User &user) {
        ifstream database("accountManager.csv");
        if (!database) {
            cerr << "ERROR: Unable to read file.";
            return;
        }

        int k = user.getKey();
        string encoded;
        while(getline(database, encoded)) {
            string encrypted = base64Decode(encoded);
            
            string decryptedLine;
            for (unsigned char c : encrypted) {
                decryptedLine += encryptDecrypt(c, k);
            }
            cout << "Decrypted Line: " << decryptedLine << endl;
        }

        database.close();
    }

};

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && (value > 1 || value < 2)) break;

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid number. Try again.\n";
    }
    cin.ignore(10000, '\n');
    return value;
}

int main() {
    User user;
    DataHandler data;
    cout << "--| Account Manager |--\n\n";
    
    cout << "1 - Log-in Account\n"
         << "2 - Register Account\n";
    //int action = readInt("Enter Choice: ");

    user.setName();
    user.setId();
    data.appendToCSV(user);
    data.readFromCSV(user);

    return 0;
}