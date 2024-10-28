#include <iostream>
using namespace std;

class Person {
	private:
		string name;
		int age;
	public:
		Person(string n, int a) {
			name = n;
			age = a;
		}
		void setName(string n) {
			name = n;
		}
		void setAge(int a) {
			if (a > 0)
				age = a;
		}
		void displayInfo(){
			cout<<"Name is: " << name << " and age is: "<< age<< endl;
		}
		void birthday() {
			age++;
		}
};

int main() {
	Person p("Atif", 35);
	p.displayInfo();
	p.setName("Ali");
	p.setAge(20);
	p.displayInfo();
	p.birthday();
	p.displayInfo();

}