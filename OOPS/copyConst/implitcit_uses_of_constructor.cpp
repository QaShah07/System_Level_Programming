#include<iostream>

class Fraction{
private: 
	int m_numerator{0};
	int m_denominator{1};
public:
	// default constructor
	Fraction(int numerator=0,int demonitor=1) : m_numerator{numerator},m_denominator{demonitor}
	{

	}
	// copy constructor
	Fraction(const Fraction &fraction) : m_numerator{fraction.m_numerator},m_denominator{fraction.m_denominator}
	{
		std::cout<<"copy constructor called\n";
	}
	// now printing the constructor
	void  print() const {
		std::cout<<m_numerator<<" "<<m_denominator<<"\n";
	}
	// 
};
void printFraction(Fraction f)
{
	f.print();
}
// nwo for generate the fracation
Fraction generateFraction(int n, int d)
{
	Fraction f{n,d};
	return  f;
}
// main fucntion for controll the thing
int main()
{
	Fraction f{5,4};
	printFraction(f);

	Fraction f2{generateFraction(1,2)};
		printFraction(f2);
		return 0;
}