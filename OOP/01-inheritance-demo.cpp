#include <iostream>
using namespace std;

// Base class
class Animal {

public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Derived class inheriting publicly from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }

        // Overriding the eat method from the base class
    void eat()  {
        cout << "Dog is eating bones" << endl;
    }
};

int main() {
    // Creating an object of the derived class
    Dog myDog;

    // Accessing inherited method from the base class
    myDog.eat();

    // Accessing method defined in the derived class
    myDog.bark();

    return 0;
}