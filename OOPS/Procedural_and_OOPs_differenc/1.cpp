#include<iostream>
#include<string_view>
// enum type wher we can access 
enum AnimalType{
	cat,
	dog,
	chicken,
};
// now for accessing something
constexpr std::string_view animalName(AnimalType type)
{
	switch(type)
	{
	case cat: return "cat";
	case dog: return "dog";
	case chicken: return "chicken";
		default: return "";
	}
}
// now for accessing properties 
constexpr int numLegs(AnimalType type)
{
	switch(type)
	{
	case cat: return 4;
	case dog: return 4;
	case chicken: return 2;
		default: return 0;
	}
}
// now main function to controll this
int main()
{
	constexpr AnimalType animal{cat};
	std::cout<<"A "<<animalName(animal)<<"has "<<numLegs(animal)<<" Legs\n";
	return 0;
}