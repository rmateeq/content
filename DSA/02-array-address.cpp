#include <iostream>
using namespace std;

int main() {
    // Integer array
    int arrInt[5] = {10, 20, 30, 40, 50};

    // Base address of the array
    int* baseAddress = arrInt;

    // Calculate the size of each element
    size_t sizeOfElement = sizeof(arrInt[0]);

    // Calculate the address of the third element (index 2)
    int* addressOfElement2 = baseAddress + 2;

    // Calculate the byte offset using sizeof
    size_t byteOffset = 2 * sizeOfElement;

    // Print the details
    cout << "Base Address of arrInt: " << baseAddress << endl;
    cout << "Size of each element: " << sizeOfElement << " bytes" << endl;
    cout << "Calculated address of arrInt[2]: " << addressOfElement2 << endl;
    cout << "Byte offset: " << byteOffset << " bytes" << endl;
    cout << "Value at arrInt[2]: " << *addressOfElement2 << endl;

    return 0;
}
