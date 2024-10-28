#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Setter method to set the radius
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        }
    }

    // Getter method to retrieve the radius
    double getRadius() const {
        return radius;
    }

    // Member function to calculate the area
    double calculateArea() const {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle myCircle;  // Creating an object of the Circle class

    // Using setter method to set the radius
    myCircle.setRadius(5.0);

    // Using getter method to retrieve the radius
    cout << "Radius of the circle: " << myCircle.getRadius() << " units" << endl;

    // Using member function to calculate the area
    cout << "Area of the circle: " << myCircle.calculateArea() << " square units" << endl;

    return 0;
}
