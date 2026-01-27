#include <iostream>

using namespace std;

class Character{
private:
    int money;
    int exp;

public:
    string cname;
    string cclass;
    int lvl;

    //Constructor
    Character(string Cname, string Cclass, int Lvl, int Money, int Exp) {
        cname = Cname;
        cclass = Cclass;
        lvl = Lvl;
        money = Money;
        exp = Exp;
    }

   //Getter
    int getMoney() {
        return money;
    }
    int getExp() {
        return exp;
    }

    //Setter
    void setMoney(int tempm) {
        money=tempm;
    }
    void setExp(int tempe) {
        exp=tempe;
    }

    void showstatsBasic(bool printName = true) {
        cout << "============================================" << endl;
            if (printName) {
                    cout << "- Name: " << cname << endl;
            }
        cout << "- Class: " << cclass << endl;
        cout << "- LVL: " << lvl << endl<< endl;
        cout << "============================================"<< endl;
    }

    void showstatsFull(bool printName = true) {
        cout << "============================================" << endl;
            if (printName) {
                cout << "- Name: " << cname << endl;
            }
        cout << "- Class: " << cclass << endl;
        cout << "- LVL: " << lvl << endl<< endl;
        cout << "============================================"<< endl;
        cout << "- Money: $" << money << endl;
        cout << "- EXP: " << exp << endl;
        cout << "--------------------------------------------"<< endl;
        cout << endl;
    }
};

int main() {
    int choice;
    int charactercount;
    int maximum = 10;

    string inp_Cname[maximum];
    string inp_Cclass[maximum];
    int inp_Lvl[maximum];
    int inp_Money[maximum];
    int inp_Exp[maximum];

    cout << "=========== Character Creation ===========" << endl;
    cout << "1. Create Without MONEY/EXP" << endl 
         << "2. Create With MONEY/EXP" << endl 
         << "=============================" << endl;
    cout << "Choice: ";
    cin >> choice;

    cout << "Characters to Make[Max 10]: ";
    cin >> charactercount;

    if(charactercount <= maximum) {

    switch (choice) {
    case 1:{
        for (int i = 0; i < charactercount; i++) {
            cout << "- Name: ";
            cin >> inp_Cname[i];

            cout << "- Class: ";
            cin >> inp_Cclass[i];

            cout << "- LVL: ";
            cin >> inp_Lvl[i];

            cout << endl;
            cout << "==== Character " << i + 1 << endl;

            Character player(inp_Cname[i], inp_Cclass[i], inp_Lvl[i], 0, 0);
            player.showstatsBasic();
        } // FORLOOP END

        int sel;
        cout << "Select a character (1 to " << charactercount << "): ";
        cin >> sel;

        sel=sel-1;
        cout << "\n Chosen Hero " << inp_Cname[sel] << endl;

        Character chosen(inp_Cname[sel], inp_Cclass[sel], inp_Lvl[sel], 0, 0);
        chosen.showstatsBasic(false);
    break;
    }
    case 2:{
        for (int i = 0; i < charactercount; i++) {
            cout << "- Name: ";
            cin >> inp_Cname[i];

            cout << "- Class: ";
            cin >> inp_Cclass[i];

            cout << "- LVL: ";
            cin >> inp_Lvl[i];

            cout << "- Money: $";
            cin >> inp_Money[i];

            cout << "- EXP: ";
            cin >> inp_Exp[i];

            cout << endl;
            cout << "==== Character" << i+1 << endl;

            Character player(inp_Cname[i], inp_Cclass[i], inp_Lvl[i], inp_Money[i], inp_Exp[i]);
            player.showstatsFull();
        }//FORLOOP END

        int sel;

        cout << "Select a character (1 to " << charactercount << "): ";
        cin >> sel;
        sel=sel-1;

        cout << "\n Chosen Hero " << inp_Cname[sel] << endl;

        Character chosen(inp_Cname[sel], inp_Cclass[sel], inp_Lvl[sel], inp_Money[sel], inp_Exp[sel]);
        chosen.showstatsFull(false);
    break;
    }
    }//SWITCHCASE END

    }//IF/ELSE END
    else
        cout << "Up To 10 Only ";
    return 0;
}