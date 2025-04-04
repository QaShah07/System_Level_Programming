#include<iostream>
// some reandom class
class Something{
    public:
    void print()
    {
        std:: cout<<"Hello shah mohammad \n";
    }
    void print() const{
        std:: cout<<"Hello shah Mohammad are you ok ? /n";
    }
};
// main function
int main()
{
    Something s1{};
    s1.print();
    const Something s2{};
    s2.print();
    return 0;
}
