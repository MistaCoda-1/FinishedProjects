#include <iostream>
using namespace std;

class CharacterClass {
    private:
        int money;       // <- Private Attribute
        int exp;         // <- Private Attribute
    public:
        string uName;    // <- Pulic Attribute
        string uClass;   // <- Pulic Attribute
        int health;      // <- Pulic Attribute
        int mana;        // <- Pulic Attribute

        // Parameterized Constructor
        CharacterClass(string n, string c, int hp, int mp) {
            uName = n;
            uClass = c;
            health = hp;
            mana = mp;
        }

        // Public Attribute Getters
        string getName() { return uName; }
        string getClass() { return uClass; }
        int getHp() { return health; }
        int getMp() { return mana; }
        
        // Private Attribute Getters
        int getMoney() { return money; } 
        int getExp() { return exp; } 

        // Private Attribute Setters
        void setMoney(int m) { money = m; }
        void setExp(int xp) { exp = xp; }
};

int main() {

    // Create `CharacterClass` object using constructor
    CharacterClass character("Dominic", "Hero", 300, 300);

    // Hardcode max values
    int maxHp = 400;
    int maxMp = 400;
    int maxExp = 5314;

    character.setMoney(9999);   // <- Set Money to 9999
    character.setExp(maxExp);   // <- Set Exp to maxExp

    // Display Public Attributes
    cout << "Player Public Attributes:\n"
         << "- Name: " << character.getName() << endl
         << "- Class: " << character.getClass() << endl
         << "- Health: " << character.getHp() << "/" << maxHp << endl
         << "- Mana: " << character.getMp() << "/" << maxMp << endl;

    cout << "\n";

    // Display Private Attributes
    cout << "Player Private Attributes:\n"
         << "- Money: " << character.getMoney() << endl
         << "- Exp: " << character.getExp() << "/" << maxExp << endl;

    return 0;
}