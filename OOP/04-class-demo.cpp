#include <iostream>
using namespace std;
// Class declaration
// Class declaration is a template for the object. It does not create anything but tells
// how the object will looks like, if created.
class Car {
    // Access specifier
    public:
        // Properties / Attributes / Data members
        string brand;
        int year;
        double price;
    //public:
        // Behavior / Function / Method / Member function
        void displayInfo() {
            cout << "Brand: " << brand << ", Year: " << year << ", Price: $" << price << endl;
    }
};

int main() {
    // Creating an object of class Car
    // It is only now when an object of type Car is actually created!
    Car myCar, yourCar;

    // Accessing and modifying data members
    myCar.brand = "Toyota";
    myCar.year = 2022;
    myCar.price = 25000.0;

    yourCar.brand = "Suzuki";
    yourCar.year = 2024;
    yourCar.price = 30000;

    // Calling a member function
    myCar.displayInfo();

    yourCar.displayInfo();

    return 0;
}