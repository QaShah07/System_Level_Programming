#include<iostream>
#include<string>

// class of employee
class Employee{
    private:
    std::string m_name{};
    // member function
    public:
    void setName(std::string& name) {m_name=name;}
    const auto& getName() const{
        return m_name;
    }

};
// now Employe is userdefined data types 
