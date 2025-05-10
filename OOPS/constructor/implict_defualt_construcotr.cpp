#include<iostream>

class Foo{
private:
	int m_x{};
	int m_y{};
	// no constructor generated
};

int main()
{
	Foo foo{};
	return 0;
}
