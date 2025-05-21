#include<iostream>

class Date
{
public:
	int m_day{};
	int m_month{};
	int m_year{};	
};
// for printing 
void printDate(const Date& date)
{
	std::cout<<date.m_day<<"/"<<date.m_month<<"/"<<date.m_year;
}
// now main fuction to controll this
int main()s
{
	Date date{13,05,2025};
	printDate(date);
	return 0; 
}