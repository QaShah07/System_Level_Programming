#include<iostream>
// class function for date
class Date{
    public:
    int year {};
    int month {};
    int day {};
    // function for increament the date
    void increamentDay()
    {
        ++day;
    }
};
// main function
int main(){
    Date today{2025,3,25};
    today.day +=1;
    today.increamentDay();
    std:: cout<<today.day;
    return 0;
}