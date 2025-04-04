#include<iostream>
#include<string>
// class of employee
class Employee{
    std::string m_name{};
    // member function
    public:
    void setName(std::string name) {m_name=name;}
    const std::string& getName(){
        return m_name;
    }
};
// main function
int main()
{
    Employee shah{};
    shah.setName("Shah Mohammad!");
    std::cout<<shah.getName()<<"\n";
    return 0;
}