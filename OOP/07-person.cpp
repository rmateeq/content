#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        if (a > 0) {
            age = a;
        }
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person person1;  // Creating an object of the Person class
    person1.setName("Shan");
    person1.setAge(25);
    person1.displayInfo();

    return 0;
}
