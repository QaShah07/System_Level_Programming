#include<iostream>
// class for use case of constructor
class Coordinate{
    private:
    int m_x{};
    int m_y{};
    int m_z{};
    // now make constructor
    public:
    Coordinate(int x,int y, int z) : m_x{x},m_y{y},m_z{z}
    {
        std::cout<<"Constructor: "<<x<<","<<y<<","<<z<<std::endl;
    }
    void print() const
    {
        std::cout<<"Co:"<<m_x<<","<<m_y<<","<<m_z<<"\n";
    }
};
// main function 
int main(){
    Coordinate c{2,4,5};
    c.print();
    return 0;
}