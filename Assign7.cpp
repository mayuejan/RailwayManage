/**
* File Name: Assign7.cpp
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
