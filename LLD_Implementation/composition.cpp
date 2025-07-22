#include <iostream>
#include <string>
using namespace std;

class Heart
{
public:
	Heart(string person_name) : person_name_{person_name} {}
	~Heart() { cout << "~Heart " << person_name_ << endl; }
	void Beats() {} // Optional

private:
	string person_name_;
};

class Person
{
public:
	Person(string person_name) : heart_(person_name) {}
	~Person() { cout << "~Person" << endl; }

private:
	Heart heart_; // composition
};

int main()
{
	Person p1("A");
	Person p2("B");
	return 0;
}
