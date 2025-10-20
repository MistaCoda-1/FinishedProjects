#include <iostream>
using namespace std;

// Simple switch statement for "dynamic" [Subjects]

string subject(int indicator) {
    switch (indicator) {
        case 0: return "English";
        case 1: return "Physics";
        default: return "Science";
    }
}

int main() {

    cout << "== Grades Analyzer 3D ==\n\n";

    int grades[2][3][3];    //[Sections][Students][Subject Grades]
    int n = 3;  //Size of the rows and columns

    cout << "//==============\n";

    //3D Array Input loops

    for (int i = 0; i < 2; i++) {

        //OUTER LOOP
        //This is the [2] in grades[2][3][3];
        //This loop indicates which iteration of [Sections] you're at.

        cout << "\nSection " << i + 1 << "\n\n";

        for (int j = 0; j < n; j++) {

            //MIDDLE LOOP
            //This is the [3] in grades[2][3][3] note- the second one.
            //This loop indicates which iteration of [Students] you're at.

            cout << "Student " << j + 1 << ":\n";

            for (int k = 0; k < n; k++) {

                //INNER-MOST LOOP
                //This is the last [3] in grades[2][3][3] note- the third one.
                //This loop indicates which iteration of [Subjects] you're at.

                string s = subject(k);  //This is the switch function on top.

                //USER INPUT
                //The cin below automatically assigns values in the 3D array in order.

                cout << "  Subject [ " << s << " ] grade: ";
                cin >> grades[i][j][k];

                /*EXAMPLE:
                
                First iteration:
                i=0,j=0,k=0

                User inputs: 10

                3D ARRAY
                
                [10] [ ] [ ]
                [ ] [ ] [ ]
                [ ] [ ] [ ]

                Second iteration:
                i=0,j=0,k=1

                User inputs: 20

                3D ARRAY

                [10] [20] [ ]
                [ ] [ ] [ ]
                [ ] [ ] [ ]

                and so forth...*/
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "//==============\n\n";



    //Data Processing
    // ! Always declare your sums to 0 to avoid random numbers !
    cout << "== Grades Viewing ==\n\n";

    //Declared outside the loop to prevent resetting it to 0.
    double overallSum = 0;

    //The triple for-loop below this is used to iterate through the whole 3D ARRAY
    for (int i = 0; i < 2; i++) {   //SECTIONS

        cout << "Section " << i + 1 << ":\n\n";

        //Declared inside the OUTER LOOP so it resets for each section.
        double sumSect = 0;

        for (int j = 0; j < n; j++) {   //STUDENTS

            //Declared inside the MIDDLE LOOP so it resets for each student.
            double sumStud = 0;

            for (int k = 0; k < n; k++) {   //SUBJECTS

                //This inner loop's main function is to sum up the inputted values.
                //This sums up all values in index [0][0][0] to index [0][0][2]
                sumStud += grades[i][j][k];

            }

            //Declare studAve as sumStud / 3 to get the average.
            double studAve = sumStud / n;  

            //Adds the current sumStud(Sum of the student's grade) into sumSect
            //Used to compute the average of the whole section.
            sumSect += sumStud;

            //Outputs the student and their average.
            cout << "Student " << j + 1 << " average: " << studAve << endl;

        }

        //Same as studAve
        //Declare sectAve as sumSect / (3 * 3) to get the average of the whole section.
        double sectAve = sumSect / (n * n); //(3 students * 3 subjects)

        //Adds sumSect to the overallSum
        //This is used to compute the overall average of both sections.
        overallSum += sumSect;

        //Outputs the section average.
        cout << "Section " << i + 1 << " average: " << sectAve << "\n\n";

    }

    //Same stuff really.
    //Declare overallAve as overallSum / (2 * 3 * 3) to get the average of both sections
    double overallAve = overallSum / (2 * n * n);   //(2 sections * 3 students * 3 subjects)

    //You guessed it, it outputs the average of both sections.
    //Congrats.
    cout << "Overall Average of both sections: " << overallAve << "\n\n";
    
    cout << "//==============";

    //SHOW FULL ARRAY
    //This snippet is purely for looking at the 3D array
    //Can also be used for copy-pasting the 3D array structure since it's alot to type.
    cout << "\n\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << grades[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}