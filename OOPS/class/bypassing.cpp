#include<iostream>
#include<string>

// class for practice
class Employee{
    private:
    int m_value{ 4 };
    // member function
    public:
    // this is not correct way basically we are providing non const refrence which is by pass the information
    auto& value() {
        return m_value;
    }
};
// main functon
int main()
{
    Employee e{};
    std::cout<<e.value()<<std::endl;
    // so there is no sence of decalingring private avoid this mistake 
    e.value()=9;
    std::cout<<e.value()<<"\n";
    return 0;
}