#include<iostream>
#include<string>
#include<fstream>
using namespace std;

char ecnrypt(char c, int key) {
    return c ^ key;
}

int main() {

    string lineToEncrypt = "╓°▓╓² √ⁿ√±▓▀╝▓▀τ■÷≈Φ";
    int key = 914;
    string encryptedLine;
    for (char c : lineToEncrypt) {
        encryptedLine += ecnrypt(c, key);
    }

    cout << "Encrypted = " << encryptedLine << endl;
    string decryptedLine;

    for (char c : encryptedLine) {
        decryptedLine += ecnrypt(c, key);
    }
    cout << "Decrypted = " << decryptedLine << endl;
    
    return 0;
}