#include <iostream>
#include <string>
class Base
{
protected:
	int value_;
public:
	Base(int value)
	:value_{value}
	{
	}
	virtual ~Base() = default;
	// getter and setter method
    std::string getName() const {return "Base";}
    int getValue() const {return value_; }
};


// Now Derived class 
class Derived: public Base
{
public:
	Derived(int value)
	:Base{value}
	{

	}
	// now getter methoda
	std::string getName() const {return "Derived";}
	int getValue() const {return value_*2; }
};

// 
int main()
{
	Derived d1{5};
	std::cout<<d1.getName()<<" "<<d1.getValue()<<"\n";
	Derived& rd1{d1};
	std::cout<<rd1.getName()<<" "<<rd1.getValue()<<"\n";
	Derived* pd1{&d1};
	std::cout<<pd1->getName()<<" "<<pd1->getValue()<<"\n";
	return 0;
}