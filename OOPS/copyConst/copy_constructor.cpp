#include<iostream>

class Fraction
{
private:
	int m_numerator{0};
	int m_denominator{1};
public:
	// construcotr
	Fraction(int numerator=0,int demonitor=1): m_numerator{numerator},m_denominator{demonitor}
	{

	}
	// print the thing
	void print(){
		std::cout<<m_numerator<<" "<<m_denominator<<"\n";
	}
};
// main function
int main(){
	Fraction f{5,3};
	Fraction fcopy{f};
	f.print();
	fcopy.print();
	return 0;
}