#include <iostream>
using namespace std;

class Lion {
private:
    string gender;
    int age;
    int speed;
public:
    
    Lion() {
        gender = "unknown";
        age = 0;
    }
    
    Lion(string g, int a, int s) : gender(g), age(a), speed(s) {}

    void roar() {
        cout<< "Raaaaaawwwrrrr....." << endl;
    }

    string prey() {
        cout << "Hunted an innocent deer...." << endl;
        return "Deer";
    }

    bool setGender(string g) { 
        if ((g == "Male") || (g == "Female")) {
            gender = g;
            return true;  
        }
        else {
            return false;
        } 
    }

    string getGender() {
        return gender;
 	}
};

int main() {
    Lion zoro("Male", 1, 20);  // Creating an object of the Car class
    //myCar.brand = "Toyota";
    Lion don;
    
    string p = zoro.prey();
    cout << "Congratulation on having a treat of " << p << " Meat" << endl;

    cout<< "The gender of don is: " << don.getGender() << endl;

    return 0;
}