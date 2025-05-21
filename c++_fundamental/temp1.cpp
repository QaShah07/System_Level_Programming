#include<iostream>
using namespace std;
template<class T>
T big(T a, T b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	cout<<big(4,5)<<endl;
	cout<<big(4.5,7.9)<<endl;
	cout<<big(7.09,9.07)<<endl;
	cout<<big("Shah","Akanksha");
	return 0;
}