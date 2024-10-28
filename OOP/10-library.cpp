#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:
    // Constructor for initializing book details
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    // Accessor methods
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getPages() const {
        return pages;
    }

    // Member function to display book information
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

int main() {
    // Creating objects of the Book class
    Book book1("The Catcher in the Rye", "J.D. Salinger", 214);
    Book book2("To Kill a Mockingbird", "Harper Lee", 281);

    // Using accessor methods to retrieve and display book information
    cout << "Book 1 Information:" << endl;
    cout << "Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "Pages: " << book1.getPages() << endl;
    cout << endl;

    // Using member function to display book information
    cout << "Book 2 Information:" << endl;
    book2.displayInfo();

    return 0;
}
