#include<iostream>
#include<string_view>
#include<string>
// parent class
class Person{
public:
	int age_;
	std::string name_;
// constructor
	Person(int age=0, std::string_view name="")
	: age_{age}, name_{name}
	{

	}
// getter method
	const std::string& getName() const {return name_;}
	int getAge() const {return age_;}

};
// derived class or subbclass
class BaseBallPlayer: public Person
{
public:
	double battingAverage_;
	int homeRuns_;
	// constructor
	BaseBallPlayer(double battingAverage=0.0, int homeRuns=0 )
	: battingAverage_{battingAverage}, homeRuns_{homeRuns}
	{

	} 

	// gette method
	double getBattingAverge() const{return battingAverage_;}
	int getHomeRuns() const { return homeRuns_;}

};
// main fucntion to control htis
int main()
{
	BaseBallPlayer player1;
	player1.name_ = "Akansha";
	std::cout<<player1.getName();
	return 0;
}