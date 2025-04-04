#include<iostream>

// class function
class Date{
    //  theser are private by default
    // public:
    int m_day{};
    int m_month{};
    int m_year{};
    // private print funciton
    void print() const{
        std:: cout<<m_day<<"/"<<m_month<<"/"<<m_year<<"\n";
    }
};
// main function
int main(){
    Date today {26,03,2025}; 
    today.m_day = 16;
    today.print();
    return 0;

}