#include<iostream>

class Simple
{
private:
	int m_id{};
public:
	// constructor
	Simple(int id): m_id{id}
	{

	}
	// get and setter method
	int getId() { return m_id;}
	void setId(int id) { m_id = id;}
	// print function
	void print(){
		std::cout<<this->m_id<<"\n";
	}
};
// main function to control oops
int main()
{
	Simple s1{1};
	s1.print();
	s1.setId(5);
	s1.print();
	return 0;
}