#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    void setDimensions(double len, double wid) {
        length = len;
        width = wid;
    }

    double calculateArea() {
        return length * width;
    }
};

int main() {
    Rectangle myRectangle;  // Creating an object of the Rectangle class
    myRectangle.setDimensions(5.0, 3.0);
    
    cout << "Area of the rectangle: " << myRectangle.calculateArea() << " square units" << endl;

    return 0;
}
