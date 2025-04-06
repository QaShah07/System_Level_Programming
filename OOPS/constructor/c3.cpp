#include<iostream>
// class for the understading of construcotr bodies function
class Demo{
    private:
    int a;
    int b;
    public:
    // constructor
    Demo(int x, int y): a{x},b{y} {
        std::cout<<"Inside Constructor Body\n";
        std::cout<<x<<" "<<y<<'\n';
    }
    // print
    void print()
    {
        std::cout<<a<<" "<<b<<"\n";
    }
};
int main()
{
    Demo d{4,5};
    // d.print();
    return 0;
}