#include <iostream>
using namespace std;

class Student {
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
    Student student1;  // Creating an object of the Student class
    student1.setName("Shahida");
    student1.setAge(20);
    student1.displayInfo();

    Student student2;  // Another object
    student2.setName("Salman");
    student2.setAge(22);
    student2.displayInfo();

    return 0;
}