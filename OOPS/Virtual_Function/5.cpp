#include<iostream>

class A {
public:
	 virtual void sayHello()
	{
		std::cout<<"Hello I am Shah Mohammad\n";
	}
};

class B: public A 
{
	void sayHello() override
	{
		std::cout<<"Hello I am Akanksha\n";
	}
};
int main()
{
	A* obj  = new B();
	obj->sayHello();
	delete obj;
	return 00;
}