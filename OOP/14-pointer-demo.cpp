#include <iostream>
using namespace std;

int main() {
    int *ptr = new int;
    *ptr = 10;

    cout << "Pointed Location: " << ptr << endl;
    cout<< "Value at Pointed Location: " << *ptr << endl;
    cout<< "Location of Pointer Itself: " << &ptr << endl;

    delete ptr;

    return 0;
}