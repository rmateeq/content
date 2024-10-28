#include <any> //class
#include <vector> //seq container
#include <stdexcept> //std exception objects
#include <iostream> // for IO
using namespace std;

class PyList {
private:
    vector<any> data;  // Uses any to store any type of data

public:
    // Append element of any type to the list
    void append(const any& value) {
        data.push_back(value); // place value at the end
    }

    // Insert element of any type at specified index
    void insert(size_t index, const any& value) {
        if (index > data.size()) {
            throw out_of_range("Index out of range");
        }
        data.insert(data.begin() + index, value);
    }

    // Remove and return element at specified index
    any pop(size_t index = -1) { //-1 is default in case parameter is not specified 
        if (index == static_cast<size_t>(-1)) {
            index = data.size() - 1;
        }
        if (index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        any value = data[index];
        data.erase(data.begin() + index);
        return value;
    }

    // Access element at specified index
    any& operator[](size_t index) {
        if (index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Get number of elements in the list
    size_t size() const {
        return data.size();
    }
};

// Helper function to print any values
void print_any(const any& val) {
    if (val.type() == typeid(int)) {
        cout << any_cast<int>(val) << '\n';
    } else if (val.type() == typeid(double)) {
        cout << any_cast<double>(val) << '\n';
    } else if (val.type() == typeid(string)) {
        cout << any_cast<string>(val) << '\n';
    } else {
        cout << "Unknown type\n";
    }
}

// Example usage
int main() {
    PyList myList;
    myList.append(10);
    myList.append(3.14);
    myList.append(string("Hello, world!"));

    for (size_t i = 0; i < myList.size(); ++i) {
        print_any(myList[i]);
    }

    any poppedValue = myList.pop(1);
    cout << "Popped: ";
    print_any(poppedValue);

    return 0;
}