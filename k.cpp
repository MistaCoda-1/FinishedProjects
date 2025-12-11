#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "+ - - - - - - - - - - - - - - - - - - - -  +\n";

    //FIND LENGTH (MANUAL)
    string originalString = "Good morning!";
    int length = 0;
    for (char c : originalString) {
        length++;
    }
    cout << "The length of the string is: " << length << endl;

    //FIND LENGTH (AUTOMATIC)
    int length2 = originalString.length();
    cout << "The length of the string is: " << length2 << endl;

    cout << "+ - - - - - - - - - - - - - - - - - - - -  +\n";

    //REVERSING A STRING (RANGE BASED)
    string reversedString = "";
    int l = originalString.length();

    for (char c : originalString) {
        reversedString = c + reversedString;
    }
    cout << "The reversed string is: " << reversedString << endl;

    //REVERSING A STRING (INDEX BASED)
    reversedString = "";
    for (int i = l - 1; i >= 0; --i) {
        reversedString += originalString[i];
    }
    cout << "The reversed string is: " << reversedString << "\n";

    cout << "+ - - - - - - - - - - - - - - - - - - - -  +\n";

    //FIND SUB-STRING
    string text = "The Jumper Jumped Over The Jumping Dog.";
    string toFind;
    cout << "Text String: " << text << endl
         << "Sub-String to Find: ";
    cin >> toFind;

    int index1 = text.find(toFind);

    if (index1 != string::npos) {
        cout << "Sub-String found at Index: " << index1 << "\n";
    } else {
        cout << "Couldn't find Sub-String.\n";
    }

    cout << "+ - - - - - - - - - - - - - - - - - - - -  +\n";

    //FIND SPECIFIC CHARACTER
    string originalText = "Hello World!";
    char charToFind = 'W';

    int index2 = originalText.find(charToFind);

    cout << "Original Text: " << originalText << "\n";
    cout << "The character '" << charToFind << "' is at index: " << index2 << "\n";

    cout << "+ - - - - - - - - - - - - - - - - - - - -  +\n";
    return 0;
}