#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// -------------------- PLAYER --------------------
class Player {
private:
    const int maxHP = 100;
    int health;
public:
    Player(int h) : health(h) {}
    void setHP(int h) { 
        health = (h > maxHP) ? maxHP : h; 
        if (health < 0) health = 0;
    }
    int getHP() { return health; }
};

// -------------------- ABILITY BASE --------------------
class Ability {
public:
    virtual void useSpell() {
        cout << "You casted a spell!\n";
    }
    virtual void spellInfo(int index) {
        cout << "Ability #" << index << " info...\n";
    }
    virtual int getAbilityStat() { return 0; }
    virtual ~Ability() {}
};

// -------------------- FIREBALL --------------------
class FireBall : public Ability {
private:
    string abilityName = "FIREBALL";
    int damage = 3;
public:
    void useSpell() override {
        cout << "\nYou casted FIREBALL!\n";
    }
    int getAbilityStat() override { return damage; }
    void spellInfo(int index) override {
        cout << "ABILITY #" << index << " NAME: " << abilityName 
             << "\nABILITY DAMAGE: " << damage << "\n";
    }
};

// -------------------- HEAL --------------------
class Heal : public Ability {
private:
    string abilityName = "HEAL";
    int healAmount = 5;
public:
    void useSpell() override {
        cout << "\nYou casted HEAL!\n";
    }
    int getAbilityStat() override { return healAmount; }
    void spellInfo(int index) override {
        cout << "ABILITY #" << index << " NAME: " << abilityName
             << "\nHEAL AMOUNT: " << healAmount << "\n";
    }
};

// -------------------- DASH --------------------
class Dash : public Ability {
private:
    string abilityName = "DASH";
    int dxP = 3;
public:
    void useSpell() override {
        cout << "\nYou DASH around the battlefield!\n";
    }
    int getAbilityStat() override { return dxP; }
    void spellInfo(int index) override {
        cout << "ABILITY #" << index << " NAME: " << abilityName
             << "\nPLAYER DISPLACEMENT: " << dxP << "\n";
    }
};

// -------------------- UTILITY FUNCTIONS --------------------
void useAllAbilities(vector<Ability*>& abilities, Player &player, int &enemyHp) {
    for (Ability* a : abilities) {
        a->useSpell();
        // Apply effect based on dynamic type
        if (FireBall* fb = dynamic_cast<FireBall*>(a)) {
            enemyHp -= fb->getAbilityStat();
        } else if (Heal* h = dynamic_cast<Heal*>(a)) {
            player.setHP(player.getHP() + h->getAbilityStat());
        }
    }
}

void displayAbilities(vector<Ability*>& abilities) {
    int index = 1;
    cout << "---------------------|\n";
    for (Ability* a : abilities) {
        a->spellInfo(index);
        cout << "---------------------|\n";
        index++;
    }
}

bool continueGame(char c) {
    c = tolower(c);
    return c == 'y';
}

// Enemy attack: 1–5 damage
void attackPlayer(Player &player) {
    int dmg = rand() % 5 + 1;
    player.setHP(player.getHP() - dmg);
    cout << "Enemy attacks you for " << dmg << " damage!\n";
}

// -------------------- MAIN --------------------
int main() {
    srand(time(0)); // Seed for random

    Player player(50);
    int enemyHp = 15;

    FireBall fireball;
    Heal heal;
    Dash dash;

    vector<Ability*> abilities = { &fireball, &heal, &dash };

    cout << "| - RPG SYSTEM - |\n\n";

    bool inGame = true;
    char cont;

    do {
        cout << "\nPLAYER HP: " << player.getHP()
             << "\nENEMY HP: " << enemyHp << "\n";
        cout << "\nPlayer Abilities:\n";
        displayAbilities(abilities);

        int spellChoice;
        cout << "Which ability do you want to use? (1-3, 4 = use all): ";
        cin >> spellChoice;

        if (spellChoice >= 1 && spellChoice <= 3) {
            abilities[spellChoice - 1]->useSpell();

            if (FireBall* fb = dynamic_cast<FireBall*>(abilities[spellChoice - 1])) {
                enemyHp -= fb->getAbilityStat();
            } else if (Heal* h = dynamic_cast<Heal*>(abilities[spellChoice - 1])) {
                player.setHP(player.getHP() + h->getAbilityStat());
            }
        } else if (spellChoice == 4) {
            useAllAbilities(abilities, player, enemyHp);
        } else {
            cout << "You wave your wand around, but nothing happens...\n";
        }

        if (enemyHp > 0) attackPlayer(player);

        cout << "\nPLAYER HP: " << player.getHP()
             << "\nENEMY HP: " << enemyHp << "\n";

        if (player.getHP() <= 0) {
            cout << "\nYou have been defeated...\n";
            break;
        } else if (enemyHp <= 0) {
            cout << "\nYou defeated the enemy!\n";
            break;
        }

        cout << "\nContinue? (y/n): ";
        cin >> cont;
        inGame = continueGame(cont);

    } while (inGame);

    cout << "\nThe story comes to an end...\n";

    return 0;
}
