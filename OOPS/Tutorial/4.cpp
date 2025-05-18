#include<iostream>
#include<string>
// class of Person
class Person{
private:
	int age_;
	std::string name_;
	std::string address_;
public:
	std::string getName(){ return name_; }
	void setName(std::string name) { name_ = name; }
	int getAge() { return age_; }
	void setAge(int age) { age_= age; }
	// function for getting age in days
	int getAgeDays()
	{
		return age_*365;
	}
};

// now main function to controll this
int main()
{
	Person p1,p2;
	p1.setAge(60);
	p1.setName("Shah Mohammad");
	std::cout<<p1.getName()<<" has "<<p1.getAgeDays();
	return 0;
}