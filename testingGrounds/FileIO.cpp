#include <iostream>
#include <string>
#include<fstream>
using namespace std;

int main() {

    ifstream inFile("sample.txt");
    string lineOfText;

    if (inFile.is_open()) {
        while (getline(inFile, lineOfText)) {
            cout << lineOfText << endl;
        }
        inFile.close();
    } else {
        cerr << "ERROR: Unable to open file for reading." << endl;
    }

    //-------------------------------------//
    //---   User Inputs to Output File  ---//
    //-------------------------------------//

    ofstream outFile("outfile.txt", ios::app);
    string userInput;

    cout << "Enter a line of text: ";
    getline(cin, userInput);
    cout << "\n";

    if (outFile.is_open()) {
        outFile << userInput << endl;
        outFile.close();

        cout << "//----------------------------------------------------//\n"
             << "//---    Line succesfully added to output file.    ---//\n"
             << "//----------------------------------------------------//\n";
    } else {
        cerr << "ERROR: Unable to open file for reading/writing." << endl;
    }

    return 0;
}