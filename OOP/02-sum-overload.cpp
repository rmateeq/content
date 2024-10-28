#include <iostream>
#include <string>

using namespace std;

// Overloaded sum() function for integers
int sum(int a, int b) {
    return a + b;
}

// Overloaded sum() function for floats
double sum(double a, double b) {
    return a + b;
}
// Overloaded sum() function for string concatenation
string sum(string a, string b) {
    return a + b; // Concatenates the strings
}

int main() {
    int x = 5, y = 3;
    double d1 = 2.5, d2 = 1.7;
    string s1 = "Hello ", s2 = "World!";

    cout << "Sum of integers: " << sum(x, y) << endl;
    cout << "Sum of floats: " << sum(d1, d2) << endl;
    cout << "Concatenation of strings: " << sum(s1, s2) << endl;

    return 0;
}
