#include<iostream>
#include<string>
// return whose alphabet come to out
const std::string& firstAlphabet(const std::string& a, const std::string& b)
{
    return (a>b) ? b : a;

}
// main function
int main()
{
    std::string hello{"hello"};
    std::string shah{"shah"};
    std::cout<<firstAlphabet(hello,shah)<<"\n";
    return 0;
}
