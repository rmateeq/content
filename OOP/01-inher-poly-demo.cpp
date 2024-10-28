#include <iostream>
#include <string>
using namespace std;

class GroceryItem {
protected:
    string name;
    double price;

public:
    GroceryItem(const string& name, double price) : name(name), price(price) {}

    // Pure virtual function for displaying information
    virtual void displayInfo() const = 0;

    // Virtual function for updating the price
    virtual void updatePrice(double newPrice) {
        price = newPrice;
    }

    virtual ~GroceryItem() {}
};

class Fruit : public GroceryItem {
    string color;

public:
    Fruit(const string& name, double price, const string& color)
        : GroceryItem(name, price), color(color) {}

    void displayInfo() const override {
        cout << "Fruit Name: " << name << ", Price: $" << price << ", Color: " << color << endl;
    }
};

class Vegetable : public GroceryItem {
    bool isOrganic;

public:
    Vegetable(const string& name, double price, bool isOrganic)
        : GroceryItem(name, price), isOrganic(isOrganic) {}

    void displayInfo() const override {
        cout << "Vegetable Name: " << name << ", Price: $" << price << ", Organic: " << (isOrganic ? "Yes" : "No") << endl;
    }
    void updatePrice(double newPrice) override {
        price += newPrice*0.5;
    }
};

int main() {
    Fruit apple("Apple", 1.99, "Red");
    Vegetable carrot("Carrot", 0.99, true);

    // Demonstrating polymorphism: A pointer to GroceryItem can point to objects of derived classes
    GroceryItem* items[] = {&apple, &carrot};

    for (int i = 0; i < 2; ++i) {
        items[i]->displayInfo(); // Polymorphic call
    }

    // Updating price using a polymorphic call
    items[0]->updatePrice(2.49);
    items[1]->updatePrice(1.09);

    cout << "\nAfter updating prices:\n";
    for (int i = 0; i < 2; ++i) {
        items[i]->displayInfo(); // Polymorphic call to show updated prices
    }

    return 0;
}
