/*Sources
* https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-setprecision //To set the precision
* https://www.interviewcake.com/concept/java/bottom-up //Just to get a more simple example of bottom-up dynamic programming
* https://www.geeksforgeeks.org/transform-c-stl-perform-operation-elements/ //How to use transform
* https://www.geeksforgeeks.org/reduce-in-cpp-stl/ //How to use reduce
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //To set up the testing framework
#include "doctest.h" //Same comment as above

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int factorial(int n);
double e(int n);

double bottom_up_e(int n);

//Code from assignment
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

//Code from assignment
double e(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return 1.0 / factorial(n) + e(n - 1);
    }
}

//Bottom up version
double bottom_up_e(int n) {
    //Create our two vectors
    vector<int> factVal = { (1) }; //Start with one in the vector as its the first number
    vector<double> temp;

    for (int i = 1; i <= n; i++) {
        factVal.push_back(factVal.at(i - 1) * i); //Compute all of the factorial values up to n and add to vector
        temp.push_back(1.0 / factVal.at(i)); //Get the division values in temp
    }

    double sum = reduce(temp.begin(), temp.end(), 1.0); //Sum it up

    return sum;
}



//Testing stuff
TEST_CASE("testing the bottom up version of e") {
    vector<double> old_e;
    vector<double> new_e;

    for (int i = 0; i <= 1000; i++) {
        old_e.push_back(e(i));
        new_e.push_back(bottom_up_e(i));
    }

    for (int i = 0; i <= 1000; i++) {
        CHECK(old_e.at(i) == new_e.at(i));
    }
}
