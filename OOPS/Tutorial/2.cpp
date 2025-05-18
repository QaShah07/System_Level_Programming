#include<iostream>

// struct class 
struct Fraction{
	int numerator{ 0 };
	int denominator{ 1 };
};

// not for print the fraction
void printFractionValue(const Fraction& f)
{
	std::cout<<f.numerator/f.denominator<<"\n";
}
// main function
int main()
{
	Fraction f{5,0};
	printFractionValue(f);
	return 0;  
}