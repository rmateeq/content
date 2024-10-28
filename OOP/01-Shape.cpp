#include <iostream>
using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function (must be overridden)
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double calculateArea() const override { return side * side; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override { return 3.14159 * radius * radius; }
};

int main() {
    Shape* shape1 = new Square(5);
    Shape* shape2 = new Circle(3);

    // Polymorphic behavior: Calls the appropriate calculateArea() based on object type
    cout << "Area of Square: " << shape1->calculateArea() << endl;
    cout << "Area of Circle: " << shape2->calculateArea() << endl;

    delete shape1;
    delete shape2;

    return 0;
}