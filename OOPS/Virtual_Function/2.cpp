#include<iostream>
using namespace std;

class Complex{
private:
	int real_, imag_;
public:
	Complex(int r=0, int i=0)
	:real_{r},imag_{i}
	{

	}
	// 
	Complex operator + (Complex const &obj)
	{
		Complex res;
		res.real_ = real_+obj.real_;
		res.imag_ = imag_+obj.imag_;
		return res;
	}
	void show() const{
		cout<<real_<<" +i"<<imag_<<endl;
	}
};
// main fucntion 
int  main()
{
	Complex c1(3,4),c2(5,6);
	Complex c3 = c1+c2;
	c3.show();
	return 0;
}