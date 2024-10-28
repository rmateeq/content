#include <iostream>
using namespace std;
int main() {
    // if statement
    int number = 10;

    if (number > 0) {
        cout << "Number is positive." << endl;
    } else if (number < 0) {
        cout << "Number is negative." << endl;
    } else {
        cout << "Number is zero." << endl;
    }

    // for loop
    for (int i = 1; i <= 5; ++i) {
        cout << "Iteration " << i << endl;
    }

    // while loop
    int countdown = 3;
    while (countdown > 0) {
        cout << "Countdown: " << countdown << endl;
        --countdown;
    }

    return 0;
}