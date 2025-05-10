#include<iostream>
#include<string>
// class of employee
class Employee
{
private:
	std::string m_name{};
	int m_id{0};
public:
	Employee(std::string name): Employee{name,0}
	{

	}
	// parametrized construcotr
	Employee(std::string name, int id) : m_name { name }, m_id { id}
	{
		std::cout<<"Employee "<<m_name<<"created \n"<<m_id;
	}
};
int main()
{
	Employee e1{"shah"};
	Employee e2{"Akansha", 42};
	return 0;
}