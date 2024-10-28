#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Constructor with one double parameter
    Circle(double r) {
        radius = r;
        cout << "Circle created with radius " << radius << endl;
    }
    // Constructor with two double parameters
    Circle(double r, double dummy) {
        radius = r * 2; // Double the radius for demonstration
        cout << "Circle created with radius " << radius << " (double constructor)" << endl;
    }
};

int main() {
    // Creating objects with different numbers of parameters
    Circle singleParam(3.5);
    Circle doubleParam(5.0, 0.0);

    return 0;
}