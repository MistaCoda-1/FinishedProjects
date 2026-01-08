#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student {
    private:
        string name;
        double grade;
        char remark;
    public:
        Student(string n, double g) : name(n), grade(g) {}

        string getName() const { return name; }
        double getGrade() const { return grade; }

        char getRemark() const {
            if (grade < 50) return 'F';
            else if (grade < 75) return 'C';
            else if (grade < 90) return 'B';
            else if (grade <= 100) return 'A';
            else return 'X';
        }

        void setName(string n) { name = n; }
        void setGrade(double g) { grade = g; }

        void dispInfo() {
            cout << "Student Name: " << name << "\n";
            cout << "Student Grade: " << grade << "\n";
            cout << "Student Remark: " << getRemark() << "\n";
        }
};

class Section {
    private:
        vector<Student> Students;
            
    public:

};

int main() {

    cout << "-- ENCAPSULATION --\n\n";

    Student s1("Dominic", 73);

    cout << "Student #1:\n";
    s1.dispInfo();

    return 0;
}