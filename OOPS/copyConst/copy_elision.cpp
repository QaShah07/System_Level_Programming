#include<iostream>

class Foo
{
public:
	// default constructor
	Foo()
	{
		std::cout<<"default constructor"<<"\n";
	}
	// Normal constructor
	Foo(int x)
	{
		std::cout<<"normal Constructor: "<<x<<"\n";
	}
	// Copy constructor
	Foo(const Foo&)
	{
		std::cout<<"copy constructor is called \n";
	}
};

// main function
int main()
{
	Foo f1;
	Foo f2{};
	Foo f3 = 3;
	Foo f4(4);
	Foo f5{5};
	Foo f6 = {6};
	Foo f7 = f3;
	Foo f8(f3);
	Foo f9{f3};
	Foo f10 = {f3};
	return 0;
}