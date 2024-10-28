#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a hash table size
const int TABLE_SIZE = 10;

// 100 students
// 3 sections
// A simple hash function
// studentid % number of sections
// 1 % 3 = 1
// 2 % 3 = 2
// 5 % 3 = 2
// 99 % 3 = 0

// Hash function to compute index
int hashFunction(const string& name) {
    int sum = 0;
    //name = "ali" -> 95+106+103 = 304
    for (char c : name) {
        sum += c;
    }
    cout<<sum<<endl;
    return sum % TABLE_SIZE;
    // 304 % 10 = 4
}

// A hash table where each index has a vector of pairs (name, student ID)
vector<vector<pair<string, int>>> hashTable(TABLE_SIZE);

// Function to insert a name and student ID into the hash table
void insert(const string& name, int id) {
    int index = hashFunction(name);
    hashTable[index].push_back(make_pair(name, id));
}

// Function to display the hash table
void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Index " << i << ": ";
        for (auto& p : hashTable[i]) {
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout << endl;
    }
}

int main() {
    // Inserting some student names and IDs
    insert("Ali", 12349);
    insert("ali", 12545);
    insert("Alice", 12345);
    insert("Bob", 23456);
    insert("Charlie", 34567);
    insert("David", 67890);

    // Display the hash table
    displayHashTable();

    return 0;
}