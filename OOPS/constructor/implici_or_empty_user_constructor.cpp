#include<iostream>

class User{
private:
	int m_a; // no default intialization 
	int m_b{};

	// construcotr
public:
	User(){

	}
	int a() const {return m_a; }
	int b() const {return m_b; }
};

// class 2 wehre we use concept of defaut constructor

class Default{
private:
	int m_a;
	int m_b {};
public: 
	Default() = default; // we are forcing to to take defualt constructor
	int a() const { return m_a; }
	int b() const { return m_b; }
};

// class 3 wehre we use implicit constructor
class Implicit {
private:
	int m_a;
	int m_b{};
public:
	int a() const { return m_a; }
	int b() const { return m_b; }
};
// main function
int main()
{
	User user{};
	std::cout<<user.a()<<" "<<user.b()<<'\n';
	Default def{};
	std::cout<<def.a()<<" "<<def.b()<<"\n";
	Implicit imp{};
	std::cout<<imp.a()<<" "<<imp.b()<<"\n";
	return 0;
}