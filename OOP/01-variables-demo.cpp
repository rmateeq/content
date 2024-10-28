#include <iostream>
using namespace std;

int main() {
    // Basic data types
    int integerVar = 5;
    double doubleVar = 3.14;
    char charVar = 'A';

    // Output to console
    cout << "Integer: " << integerVar << endl;
    cout << "Double: " << doubleVar << endl;
    cout << "Character: " << charVar << endl;

    // User input
    int userInput;
    cout << "Enter an integer: ";
    cin >> userInput;
    cout << "You entered: " << userInput << endl;

    return 0;
}