#include <iostream>
#include <string>

// class of person
class Person {
private:
    int age_;
    std::string name_;
    std::string address_;
public:
    // constructor
    Person(int age, std::string name, std::string address)
        : age_{age}, name_{name}, address_{address}
    {
    }

    // getter methods
    int getAge() const { return age_; }
    std::string getName() const { return name_; }
    std::string getAddress() const { return address_; }

    // calculate age in months
    int getAgeMonth() const { return age_ * 12; }
};

// main function
int main() {
    Person p1{21, "Shah and Akansha", "IIT Patna"};
    std::cout << p1.getName() << " has a lover, age in months: " 
              << p1.getAgeMonth() << ", Address: " << p1.getAddress() << "\n";
    return 0;
}
