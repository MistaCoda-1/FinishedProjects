#include <iostream>
using namespace std;

class Mother{
    protected:
        string maidenName;
        string eyeColor;
        string skinColor;
        
    public:
        Mother (string maidenName,string eyeColor,string skinColor){
        this -> maidenName = maidenName;
        this -> eyeColor = eyeColor;
        this -> skinColor = skinColor;
    }
    void displayMother(){
        cout << endl;
        cout << "|========= Mother ==========|" << endl;
        cout << "Maiden Name:" <<" "<< maidenName << endl;
        cout << "Eye Color:" <<" "<< eyeColor << endl;
        cout << "Skin Color:" <<" "<< skinColor << endl;
    }
};

class Father{
    protected:
        string surname;
        string personality;
        double height;
        
    public:
        Father (string surname,string personality,double height){
        this -> surname = surname;
        this -> personality = personality;
        this -> height = height;
    }    
    void displayFather(){
        cout << endl;
        cout << "|========= Father ==========|" << endl;
        cout << "Surname:" <<" "<<  surname << endl;
        cout << "Personality:" <<" "<<  personality << endl;
        cout << "Height:" <<" "<<  height << endl;
    }
};

class Child: public Mother, public Father {
    private:
        string firstname;
        int age;
                
    public:
    Child (string firstname, int age,string maidenName,
    string eyeColor, string skinColor,
    string surname,string personality,
    int height):
                
        Mother (maidenName, eyeColor, skinColor), Father (surname,personality,height){
        this-> firstname = firstname;
        this-> age = age;
    }
    void displayChild() {
        cout << endl;
        cout << "|========= CHILD INFO ==========|" << endl;
        cout << "Full Name:" <<" "<< firstname << " " << maidenName << " " << surname << " " << endl;
        cout << "Age:" <<" "<<age << endl << endl;
        cout << "[MOM INHERITANCE]" << endl;
        cout << "Maiden Name:" <<" "<< maidenName << endl;
        cout << "Eye Color:" <<" "<< eyeColor << endl;
        cout << "Skin Color:" <<" "<<skinColor << endl << endl;
        cout << "[DAD INHERITANCE]" << endl;
        cout << "Surname:" <<" "<< surname << endl;
        cout << "Personality:" << " "<< personality << endl;
        cout << "Height:"<<" "<< height<< endl;
    }
};
int main()
{
    Child son("Harry",60,"Lopez","Black","Brown","Roque","Normal",5.5);
    Child daughter("Yui",26,"Gomez","Black","White-ish Brown","Martinez","Mabait",4.9);
    
    son.displayChild();
    son.displayMother();
    son.displayFather();
    
    cout << endl << endl << "============================================" << endl << endl;
    
    daughter.displayChild();
    daughter.displayMother();
    daughter.displayFather();
    
    return 0;
}