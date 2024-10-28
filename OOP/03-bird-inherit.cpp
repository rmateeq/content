#include <iostream>
using namespace std;
class Animal {
public:
    string name;
    void makeSound() {
        cout << "Generic Animal Sound" << endl;
    }
};

class Bird : public Animal {
public:
    void fly() {
        cout << "Bird flying" << endl;
    }
};

int main() {
    Animal dog;
    dog.name = "Dog";
    dog.makeSound();

    Bird parrot;
    parrot.name = "Parrot";
    parrot.fly();
    return 0;
}


