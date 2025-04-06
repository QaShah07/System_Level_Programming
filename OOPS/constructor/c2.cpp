#include<iostream>

class Demo{
    private:
    int a = 10; // default memeber intilizer
    int b;
    int c;
    public:
    // constructor
    Demo(int val): c(val){};
    void print()
    {
        std::cout<<a<<" "<<b<<" "<<c;
    }

};
int main()
{
    Demo d{11};
    d.print();
    return 0;
}