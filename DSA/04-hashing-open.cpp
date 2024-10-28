#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    int BUCKET;
    vector<int> table;
    vector<bool> filled;

public:
    HashTable(int b) : BUCKET(b), table(b, -1), filled(b, false) {}

    int hashFunction(int x) {
        return x % BUCKET;
    }
    void insertItem(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (filled[index]) {
            index = (index + 1) % BUCKET;
            i++;
            if (i == BUCKET) {
                cout << "Hash table is full\n";
                return;
            }
        }
        table[index] = key;
        filled[index] = true;
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (filled[index]) {
            if (table[index] == key) {
                table[index] = -1;
                filled[index] = false;
                return;
            }
            index = (index + 1) % BUCKET;
            i++;
            if (i == BUCKET) {
                cout << "Key not found\n";
                return;
            }
        }
        cout << "Key not found\n";
    }
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            if (filled[i])
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "empty" << endl;
        }
    }
};

int main() {
    int keys[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(keys)/sizeof(keys[0]);

    HashTable ht(10);

    for (int i = 0; i < n; i++)
        ht.insertItem(keys[i]);

    ht.displayHash();

    ht.deleteItem(20);
    ht.displayHash();

    return 0;
}