#include<iostream>
#include<string_view>
// struct for the cat
struct  Cat
{
	std::string_view name{"cat"};
	int numLegs{4};
};
// struct for the Dog

struct Dog
{
	std::string_view name{"dog"};
	int numLegs{4};
};
// stcut for chicken
struct Chicken{
	std::string_view name{"chicken"};
	int numLegs{ 2};
};


// now come to main fucntion
int main()
{
	Cat animal;
	std::cout<<" a "<<animal.name<<" has "<<animal.numLegs<<"Legs\n";
	return 0;
}