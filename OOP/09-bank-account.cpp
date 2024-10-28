#include <iostream>
using namespace std;

class BankAccount {
private:
    // Not initialized
    double balance;

public:
    // Public member function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        }
    }

    // Public member function to check balance
    double checkBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount;  // Creating an object of the BankAccount class

    // Using public member functions to interact with the object
    myAccount.deposit(1000);
    cout << "Current balance: " << myAccount.checkBalance() << endl;

    return 0;
}
