#include <iostream>
using namespace std;

class Base {
    private:
        string firstName;
        string lastName;
        string personality;
        string eyeColor;
    public:
        Base(string fn, string ln, string p, string ec) : 
            firstName(fn),
            lastName(ln),
            personality(p),
            eyeColor(ec)
        {  }

        string getFname() { return firstName; }
        string getLname() { return lastName; }
        string getPersona() { return personality; }
        string getEyecol() { return eyeColor; }
};

class Derived : public Base {
    private:
        string derivedFname;
        string ambition;
        string hairColor;
    public:
        Derived(string fn, string ln, string p, string ec, string dFname, string a, string hc) : 
            Base(fn, ln, p, ec),
            derivedFname(dFname),
            ambition(a),
            hairColor(hc)
        { }

        void printBase() {
            cout << "=====================================\n";
            cout << "First Name: " << getFname() << "\n"
                 << "Last Name: " << getLname() << "\n"
                 << "Personality: " << getPersona() << "\n"
                 << "Eye Color: " << getEyecol() << "\n";
            cout << "=====================================\n";
        }

        void printDerived() {
            cout << "=====================================\n";
            cout << "Derived First Name: " << derivedFname << "\n"
                 << "Inherited Last Name: " << getLname() << "\n"
                 << "Inherited Personality: " << getPersona() << "\n"
                 << "Inherited Eye Color: " << getEyecol() << "\n"
                 << "Derived Ambition: " << ambition << "\n"
                 << "Derived Hair Color: " << hairColor << "\n";
            cout << "=====================================\n";
        }
};

int main() {

    cout << "== INHERITANCE ==\n";

    Derived child1("Jobert", "Einstein", "Genius", "Brown", "Mark", "Scientist", "Black");
    Derived child2("Nikola", "Tesla", "Hard-working", "Black", "John", "Inventor", "Black");
    Derived child3("Kym", "Legaspi", "Anxious", "Brown", "Ibuki","Game-Developer", "Brown");

    cout << "\nObject # 1:\n";
    child1.printBase();
    cout << "\n";
    child1.printDerived();

    cout << "\nObject # 2:\n";
    child2.printBase();
    cout << "\n";
    child2.printDerived();

    cout << "\nObject # 3:\n";
    child3.printBase();
    cout << "\n";
    child3.printDerived();

    return 0;
}