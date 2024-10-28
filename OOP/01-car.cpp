#include <iostream>
using namespace std;
class Car {
private:
    string brand;
    int year;
public:
    void setBrand(string b) { brand = b; }
    bool setYear(int y) {
    	if ((year < 2010) || (year > 2022)){
    		return false;
    	}
    	else {
     		year = y; 
     		return true;
     	}
 	}
};

int main() {
    Car myCar;  // Creating an object of the Car class
    //myCar.brand = "Toyota";
    myCar.year = 2010;

    myCar.setBrand("Toyota");
    bool year_status = myCar.setYear(2009);
    if (year_status == true){
    	cout<< "Record Entered"<< endl;
    }
    else{
    	cout << "Invalid Model" << endl;
    }
    return 0;
}