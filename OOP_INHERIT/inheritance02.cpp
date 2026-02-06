#include <iostream>
using namespace std;

class BaseClass1 {  // FATHER
    private:
        string fname;
        string middleInitial;
        string surname;
        string eyeColor;
        string height;
    public:
        BaseClass1(string fn, string mi, string s, string ec, string h) : 
            fname(fn),
            middleInitial(mi),
            surname(s),
            eyeColor(ec),
            height(h)
        {  }

        string getFname() const { return fname; }
        string getMidInit() const { return middleInitial; }
        string getSurname() const { return surname; }
        string getEyeColor() const { return eyeColor; }
        string getHeight() const { return height; }
};

class BaseClass2 {  // MOTHER
    private:
        string fname;
        string maidenName;
        string surname;
        string hairColor;
        string personality;
    public:
        BaseClass2(string fn, string mn, string s, string hc, string p) : 
            fname(fn),
            maidenName(mn),
            surname(s),
            hairColor(hc),
            personality(p)
        {  }

        string getFname() const { return fname; }
        string getMaidenName() const { return maidenName; }
        string getSurname() const { return surname; }
        string getHairColor() const { return hairColor; }
        string getPersonality() const { return personality; }
};

class DerivedClass : public BaseClass1, public BaseClass2{    // CHILD
    private:
        string fname;
        string ambitions;
        string business;
    public:
        DerivedClass(
            //FATHER
            string f_fn, string f_mi, string f_s, string f_ec, string f_h,
            //MOTHER
            string m_fn, string m_mn, string m_s, string m_hc, string m_p,
            // CHILD
            string fn, string a, string b
        ) 
        : BaseClass1(f_fn, f_mi, f_s, f_ec, f_h),
          BaseClass2(m_fn, m_mn, m_s, m_hc, m_p),
          fname(fn),
          ambitions(a),
          business(b)
        {  }

        void displayBase1() const {
            cout << "=== FATHER INFO ===\n";
            cout << "First Name: " << BaseClass1::getFname() << "\n"
                << "Middle Initial: " << BaseClass1::getMidInit() << "\n"
                << "Surname: " << BaseClass1::getSurname() << "\n"
                << "Eye Color: " << BaseClass1::getEyeColor() << "\n"
                << "Height: " << BaseClass1::getHeight() << "\n\n";
        }

        void displayBase2() const {
            cout << "=== MOTHER INFO ===\n";
            cout << "First Name: " << BaseClass2::getFname() << "\n"
                << "Maiden Name: " << BaseClass2::getMaidenName() << "\n"
                << "Surname: " << BaseClass2::getSurname() << "\n"
                << "Hair Color: " << BaseClass2::getHairColor() << "\n"
                << "Personality: " << BaseClass2::getPersonality() << "\n\n";
        }

        void displayDerived() const {
            cout << "=== CHILD INFO ===\n";
            cout << "First Name: " << fname << "\n"
                << "Middle Name: " << BaseClass2::getMaidenName() << "\n"
                << "Surname: " << BaseClass1::getSurname() << "\n\n";

            cout << "[ INHERITED FROM FATHER ]\n"
                << "Eye Color: " << BaseClass1::getEyeColor() << "\n"
                << "Height: " << BaseClass1::getHeight() << "\n\n";

            cout << "[ INHERITED FROM MOTHER ]\n"
                << "Hair Color: " << BaseClass2::getHairColor() << "\n"
                << "Personality: " << BaseClass2::getPersonality() << "\n\n";

            cout << "Ambition: " << ambitions << "\n"
                << "Business: " << business << "\n\n";
        }
};

int main() {

    DerivedClass object1(
        // FATHER
        "Carlos", "M", "Reyes", "Brown", "5'9\"",
        // MOTHER
        "Maria", "Santos", "Reyes", "Black", "Caring",
        // CHILD
        "Daniel", "Software Engineer", "Tech Startup"
    );

    DerivedClass object2(
        // FATHER
        "Jonathan", "L", "Cruz", "Hazel", "5'11\"",
        // MOTHER
        "Elaine", "Garcia", "Cruz", "Brown", "Strict",
        // CHILD
        "Marcus", "Game Developer", "Indie Studio"
    );

    DerivedClass object3(
        // FATHER
        "Robert", "K", "Mendoza", "Black", "6'0\"",
        // MOTHER
        "Angela", "Lopez", "Mendoza", "Blonde", "Cheerful",
        // CHILD
        "Ethan", "Entrepreneur", "Coffee Shop"
    );

    cout << "== OBJECT #1 ==\n\n";

    object1.displayBase1();
    object1.displayBase2();
    object1.displayDerived();

    cout << "== OBJECT #2 ==\n\n";

    object2.displayBase1();
    object2.displayBase2();
    object2.displayDerived();

    cout << "== OBJECT #3 ==\n\n";
    
    object3.displayBase1();
    object3.displayBase2();
    object3.displayDerived();

    return 0;
}