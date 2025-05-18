#include<iostream>

struct Date
{
	int day{};
	int month{};
	int year{};
};

// not for printing 
void printdate(const Date& date)
{
	std::cout<<date.day<<"/"<<date.month<<"/"<<date.year;
}
// main function
int main()
{
	Date date{13,05,2025};
	printdate(date);
	return 0;
}
