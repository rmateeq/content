#include <iostream>
using namespace std;
// Function declaration
void greet() {
    cout << "Hello, world!" << endl;
}

// Function with parameters and return value
int add(int a, int b) {
    return a + b;
}

int main() {
    // Calling a function
    greet();
    
    // Using a function with parameters
    int sum = add(3, 4);
    cout << "Sum: " << sum << endl;

    return 0;
}