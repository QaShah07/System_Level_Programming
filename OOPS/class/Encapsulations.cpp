#include<iostream>
#include<string>
#include<string_view>

// class giving that case
class Employee{
    private:
    std::string m_name{};
    char m_f_letter{};
    // Encapsulate using getter and setter
    public:
    void setName(std::string_view name){
        m_name = name;
        m_f_letter = name.front();
    }
    // print is the member function to show the private 
    void print() const{
        std::cout<<"Employe: "<<m_name<<" has first letter is "<<m_f_letter<<"\n";
    }
};
// main function
int main()
{
    Employee e{};
    e.setName("Shah Mohammad");
    e.print();
    e.setName("Akansha");
    e.print();
    return 0;
}