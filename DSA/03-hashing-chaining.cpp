#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
    int BUCKET;
    vector<list<int>> table;

public:
    HashTable(int b) {
        BUCKET = b;
        table.resize(b);
    }

    int hashFunction(int x) {
        return x % BUCKET;
    }
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    int keys[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(keys)/sizeof(keys[0]);
    //    = 36 / 4 = 9

    HashTable ht(10);

    for (int i = 0; i < n; i++)
        ht.insertItem(keys[i]);

    ht.displayHash();

    ht.deleteItem(20);
    ht.displayHash();

    return 0;
}