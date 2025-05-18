#include <iostream>
#include <string>
#include <string_view>

// Base class
class Student {
private:
    std::string name_;
    std::string branch_;
    int batch_year_;
public:
    Student(std::string_view name = "", std::string_view branch = "", int batch_year = 0)
        : name_{name}, branch_{branch}, batch_year_{batch_year} {}

    const std::string& getName() const { return name_; }
    const std::string& getBranch() const { return branch_; }
    int getBatchYear() const { return batch_year_; }
};

// Derived class
class Department : public Student {
private:
    std::string department_;
    std::string rollNo_;
public:
    Department(std::string_view name, std::string_view branch, int batch_year,
               std::string_view department, std::string_view rollNo)
        : Student{name, branch, batch_year}, department_{department}, rollNo_{rollNo} {}

    const std::string& getDepartment() const { return department_; }
    const std::string& getRollNo() const { return rollNo_; }
};

int main() {
    Department d1{"shah", "mech", 2022, "mechanical", "2201ME60"};
    std::cout << d1.getName() << std::endl;
    std::cout << d1.getDepartment() << std::endl;
    std::cout << d1.getRollNo() << std::endl;
}
