#include<iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
};
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

void makeAnimalsSpeak(Animal& animal) {
    animal.makeSound(); // Dynamic binding: Calls Dog::makeSound() or Cat::makeSound()
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalsSpeak(dog);  // Outputs "Woof!"
    makeAnimalsSpeak(cat);  // Outputs "Meow!"
}