#include<iostream>
#include<string>
#include<string_view>
class Ball{
private:
	std::string color_;
	double radius_;

public:
	// constructor
	Ball(std::string_view color, double radius)
	: color_{ color }, radius_{ radius }
	{

	}
	// getter method for access this
	const std::string getColor() const {return color_; }
	double getRadius() const {return radius_; }
	
};
void print(const Ball& ball)
	{
		std::cout<<"Ball("<<ball.getColor()<<", "<<ball.getRadius()<<" )";
	}
// main function
int main()
{
	Ball blue {"blue", 10.0};
	print(blue);
	Ball red {"red", 12.0};
	print(red);
	return 0;
}