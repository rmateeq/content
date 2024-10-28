#include <iostream>
#include <string>
using namespace std;

class GroceryItem {
protected:
    string name;
    double price;

public:
    GroceryItem(const string& name, double price) : name(name), price(price) {}

    virtual void displayInfo() const = 0;

    // Implementing updatePrice in the base class
    virtual void updatePrice(double newPrice) {
        price = newPrice;
    }

    virtual ~GroceryItem() {}
};


class Fruit : public GroceryItem {
protected:
    string color;

public:
    Fruit(const string& name, double price, const string& color)
        : GroceryItem(name, price), color(color) {}

    void displayInfo() const override {
        cout << "Fruit Name: " << name << ", Price: $" << price << ", Color: " << color << endl;
    }
};

class Vegetable : public GroceryItem {
protected:
    bool isOrganic;

public:
    Vegetable(const string& name, double price, bool isOrganic)
        : GroceryItem(name, price), isOrganic(isOrganic) {}

    void displayInfo() const override {
        cout << "Vegetable Name: " << name << ", Price: $" << price << ", Organic: " << (isOrganic ? "Yes" : "No") << endl;
    }
};

class Dairy : public GroceryItem {
protected:
    string expirationDate;
    bool isOrganic;

public:
    Dairy(const string& name, double price, const string& expirationDate, bool isOrganic)
        : GroceryItem(name, price), expirationDate(expirationDate), isOrganic(isOrganic) {}

    void displayInfo() const override {
        cout << "Dairy Name: " << name << ", Price: $" << price << ", Expiration Date: " << expirationDate << ", Organic: " << (isOrganic ? "Yes" : "No") << endl;
    }
};

class Berry : public Fruit {
private:
    string* berryType; // Dynamically allocated
    bool isSeedless;

public:
    // Constructor with berryType and isSeedless
    Berry(const string& name, double price, const string& color, const string& type, bool seedless)
        : Fruit(name, price, color), isSeedless(seedless), berryType(new string(type)) {}

    // Second constructor for default seedless value
    Berry(const string& name, double price, const string& color, const string& type)
        : Fruit(name, price, color), isSeedless(true), berryType(new string(type)) {}

    void displayInfo() const override {
        Fruit::displayInfo();
        cout << "Berry Type: " << *berryType << ", Seedless: " << (isSeedless ? "Yes" : "No") << endl;
    }

    // Destructor to deallocate dynamic memory
    ~Berry() {
        delete berryType;
    }
};

class LeafyGreen : public Vegetable {
private:
    string* species; // Dynamically allocated
    bool isWashed;

public:
    // Constructor with species and isWashed
    LeafyGreen(const string& name, double price, bool isOrganic, const string& speciesName, bool washed)
        : Vegetable(name, price, isOrganic), isWashed(washed), species(new string(speciesName)) {}

    // Second constructor for default isWashed value
    LeafyGreen(const string& name, double price, bool isOrganic, const string& speciesName)
        : Vegetable(name, price, isOrganic), isWashed(false), species(new string(speciesName)) {}

    void displayInfo() const override {
        Vegetable::displayInfo();
        cout << "Species: " << *species << ", Washed: " << (isWashed ? "Yes" : "No") << endl;
    }

    // Destructor to deallocate dynamic memory
    ~LeafyGreen() {
        delete species;
    }
};

class Cheese : public Dairy {
private:
    string* cheeseType; // Dynamically allocated
    int ageDays;

public:
    // Constructor with cheeseType and ageDays
    Cheese(const string& name, double price, const string& expirationDate, bool isOrganic, const string& type, int age)
        : Dairy(name, price, expirationDate, isOrganic), ageDays(age), cheeseType(new string(type)) {}

    // Second constructor for a default ageDays value
    Cheese(const string& name, double price, const string& expirationDate, bool isOrganic, const string& type)
        : Dairy(name, price, expirationDate, isOrganic), ageDays(0), cheeseType(new string(type)) {}

    void displayInfo() const override {
        Dairy::displayInfo();
        cout << "Cheese Type: " << *cheeseType << ", Age: " << ageDays << " days" << endl;
    }

    // Destructor to deallocate dynamic memory
    ~Cheese() {
        delete cheeseType;
    }
};

#include <iostream>

int main() {
    // Create instances of derived classes
    Berry berry("Strawberry", 2.99, "Red", "Wild", true);
    LeafyGreen spinach("Spinach", 1.99, true, "Savoy", true);
    Cheese cheddar("Cheddar Cheese", 5.49, "2024-01-01", true, "Aged", 60);

    // Array of base class pointers to demonstrate polymorphism
    GroceryItem* items[3];

    // Assign derived class objects to base class pointers
    items[0] = &berry;
    items[1] = &spinach;
    items[2] = &cheddar;

    // Display information about each item using polymorphism
    cout << "Displaying Grocery Items Information:" << endl;
    for (int i = 0; i < 3; ++i) {
        items[i]->displayInfo();
        cout << endl;
    }

    // Demonstrate use of mutator methods
    cout << "Updating Prices..." << endl;
    items[0]->updatePrice(3.29); // Updating price for berry
    items[1]->updatePrice(2.09); // Updating price for spinach
    items[2]->updatePrice(5.99); // Updating price for cheddar

    // Display information again to show updated prices
    cout << "Displaying Updated Grocery Items Information:" << endl;
    for (int i = 0; i < 3; ++i) {
        items[i]->displayInfo();
        cout << endl;
    }

    // No explicit deletion of dynamically allocated memory in Berry, LeafyGreen, and Cheese objects is needed here
    // since we didn't use `new` for these objects. The destructors will be called automatically when the objects
    // go out of scope, which will clean up the dynamic memory within those objects.
    return 0;
}