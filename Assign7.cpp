/**
* File Name: Assign7.cpp
* Academic Integrity Statement: 
* I certify that, while others may have assisted me in brainstorming, debugging, and validating this program, 
* the program itself is my own work. I understand that submitting code that is the work of other individuals 
* is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or 
* course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my 
* original work to another individual could also result in zero credit for the assignment, or course failure 
* and a report to the Academic Dishonesty Board. See Academic Integrity for Students
Links to an external site.
* 
* Assisted by and Assisted line numbers:Assisted by "https://www.youtube.com/watch?v=GBST5uQ_yos&t=735s" to gain
* understanding of stack concept,Assisted line (28 ).Assisted by "https://www.youtube.com/watch?v=EaHFhms_Shw&t=249s"
* because im a bit forgot file handleing, assisted line (83 ).
* Your Name: YUERAN MA
* Your PSU user ID:  ymm5252
* Course title: CMPSC122 Summer 2024
* Description: In this project,I implemented STL stack and was able to solve more realistic issues.I firstly declared a 
* bool function to tell whether the need can be meet, this fucntion later bocome the most important part of this project.
* at main function, I spent a lot of time on the first value received becasue it decides the total size of this array,
* and have the power of terminating the programme.
**/

#include <iostream>

#include <fstream>

#include <stack>

using namespace std;



bool pass(int size, int* supposedArray) {

    stack<int> magazine;//I would imagine stack as magazine if a gun

    int upcomming = 1;



    for (int i = 0; i < size; ++i) {//to grant the carriage that we're handling into static number

        int numCarriage = supposedArray[i];

        while ((upcomming <= size) && (magazine.empty() || magazine.top() != numCarriage)) {

            magazine.push(upcomming);

            upcomming=upcomming+1;

        }

        if (!magazine.empty() && magazine.top() == numCarriage) {

            magazine.pop();

        }
        else {

            return false;

        }

    }

    return true;

}



int main() {

    int size = 1000;

    int numFirst;

    int* supposedArray;

    fstream myFile;

    myFile.open("A7in.txt");



    if (!myFile) {

        cout << "The file doesn't seems to open, please kindly check again" << endl;

        return 0;

    }



    while (true) {

        myFile >> size;

        if (size == 0) {

            break;

        }



        supposedArray = new int[size];  //corrected memory allocation location



        while (true) {

            myFile >> numFirst;

            if (numFirst == 0) {

                break;

            }



            supposedArray[0] = numFirst;

            for (int i = 1; i < size; ++i) {//because the scinario of i=0 is already discussed

                myFile >> supposedArray[i];

            }



            if (pass(size, supposedArray)) {

                cout << "Yes" << endl;

            }
            else {

                cout << "No" << endl;

            }

        }



        delete[] supposedArray;  // in case memory leakage


    }



    myFile.close();

    return 0;

}
/*sample output:
No
Yes
No
No
No
Yes
Yes
*/