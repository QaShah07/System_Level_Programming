#include<iostream>

// class of twonumber
class Shah{
    private:
    int m_x{};
    int m_y{};
    // constructor but it is public
    public:
    Shah(int x, int y)
    {
        // it is just for testing constructor is working or not
        std::cout<<x<<"Hello"<<y<<"construcor is working fine"<<"\n";
    }
    // public member function or print the value of the class
    void print()
    {
        std::cout<<m_x<<"constructor set the input correct"<<m_y<<"\n";
    }
};
int main()
{
    Shah c{4,7};
    std::cout<<"object create first"<<"\n";
    c.print();
    return 0;

}