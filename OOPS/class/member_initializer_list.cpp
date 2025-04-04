#include<iostream>
// class
class Coordinate{
    private:
    int m_x{};
    int m_y{};
    int m_z{};
    // now come to the constructor
    public:
    Coordinate(int x, int y, int z): m_x{x},m_y{y},m_z{z}
    {

    }
    // printing fucntion to print
    void print() const{
        std::cout<<"Coordinate of Shah: "<<m_x<<","<<m_y<<","<<m_z<<"\n";

    }
};
// main function
int main()
{
    Coordinate c{2,3,4};
    c.print();
    return 0;
}