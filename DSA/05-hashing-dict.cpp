#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> employeeDirectory;

    // Inserting key-value pairs
    employeeDirectory[101] = "Alice";
    employeeDirectory[102] = "Bob";
    employeeDirectory[103] = "Charlie";
    // Retrieving values using keys
    cout << "Employee 101: " << employeeDirectory[101] << endl;
    cout << "Employee 102: " << employeeDirectory[102] << endl;
    cout << "Employee 103: " << employeeDirectory[103] << endl;

    // Checking if a key exists
    int key = 104;
    if (employeeDirectory.find(key) != employeeDirectory.end()) {
        cout << "Employee " << key << ": " << employeeDirectory[key] << endl;
    } else {
        cout << "Employee " << key << " not found." << endl;
    }
    // Deleting a key-value pair
    employeeDirectory.erase(102);

    // Displaying the dictionary
    cout << "Employee Directory:" << endl;
    for (auto& pair : employeeDirectory) {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }

    return 0;
}