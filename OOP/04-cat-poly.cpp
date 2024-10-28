#include <iostream>
using namespace std;
class Animal {
public:
    string name;
    void virtual makeSound() {
        cout << "Generic Animal Sound" << endl;
    }
};

class Bird : public Animal {
public:
    void fly() {
        cout << "Bird flying" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow" << endl;
    }
};


int main() {
    // Creating objects of Animal, Bird, and Cat
    Animal genericAnimal;
    Bird sparrow;
    Cat fluffy;

    // Demonstrating inheritance
    cout << "Inheritance Example:" << endl;
    genericAnimal.makeSound();  // Output: Generic Animal Sound
    sparrow.makeSound();        // Output: Generic Animal Sound (inherited from Animal)
    sparrow.fly();              // Output: Bird flying

    fluffy.makeSound();         // Output: Meow (overrides makeSound() in Cat)
    cout << endl;

    // Demonstrating polymorphism using pointers and references
    cout << "Polymorphism Example:" << endl;
    Animal* animalPtr = &sparrow; // Pointer to a Bird object (upcasting)
    animalPtr->makeSound();      // Output: Generic Animal Sound (polymorphic behavior)

    Animal& animalRef = fluffy;  // Reference to a Cat object (upcasting)
    animalRef.makeSound();       // Output: Meow (polymorphic behavior)

    return 0;
}
