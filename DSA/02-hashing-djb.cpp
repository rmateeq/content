#include <iostream>
#include <string>
using namespace std;

unsigned long djb2Hash(const string& str) {
    unsigned long hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
        //hash = hash * 33 + ASCII value
        // 0  0 1 1 0 = 6
        // left shift by 2
        // 1  1 0 0 0 = 24
        // 16 8 0 0 0 = 24
    }
    return hash;
}

int main() {
    string key1 = "example";
    string key2 = "Example"; // Different case, different hash value
    string key3 = "another_example";

    cout << "Hash of \"" << key1 << "\": " << djb2Hash(key1) << endl;
    cout << "Hash of \"" << key2 << "\": " << djb2Hash(key2) << endl;
    cout << "Hash of \"" << key3 << "\": " << djb2Hash(key3) << endl;

    return 0;
}