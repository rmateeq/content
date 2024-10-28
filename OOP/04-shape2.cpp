#include <iostream>
#include <string>

// Base class representing a geometric shape
class Shape {
public:
    // Common method to get the type of the shape
    std::string getType() const {
        return "Generic Shape";
    }

    // Common method to calculate the area
    virtual double calculateArea() const {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    // Constructor for Circle
    Circle(double r) : radius(r) {}

    // Overridden method to get the type of the shape
    std::string getType() const {
        return "Circle";
    }

    // Overridden method to calculate the area
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
        // Specific method for Circle
    void setRadius(double r) {
        radius = r;
    }
};

// Derived class representing a specific shape: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor for Rectangle
    Rectangle(double l, double w) : length(l), width(w) {}
        // Overridden method to get the type of the shape
    std::string getType() const {
        return "Rectangle";
    }

    // Overridden method to calculate the area
    double calculateArea() const override {
        return length * width;
    }

    // Specific method for Rectangle
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }
};
int main() {
    // Creating objects of the derived classes
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Using the "is-a" relationship
    Shape* shape1 = &circle;    // Circle is-a Shape
    Shape* shape2 = &rectangle; // Rectangle is-a Shape

    // Using common methods
    std::cout << "Type of shape1: " << shape1->getType() << ", Area: " << shape1->calculateArea() << std::endl;
    std::cout << "Type of shape2: " << shape2->getType() << ", Area: " << shape2->calculateArea() << std::endl;

    return 0;
}