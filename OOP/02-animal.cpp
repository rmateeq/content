#include <iostream>
using namespace std;
class Animal {
public:
    string name;
    void makeSound() {
        cout << "Generic Animal Sound" << endl;
    }
};

int main() {
    Animal dog;
    dog.name = "Dog";
    dog.makeSound();
    return 0;
}
