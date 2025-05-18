#include <iostream>
#include <string>
#include <string_view>

// Base class
class Customer {
private:
    std::string name_;
    std::string collegeName_;
    std::string branch_;
public:
    Customer(std::string_view name = "", std::string_view collegeName = "", std::string_view branch = "")
        : name_{name}, collegeName_{collegeName}, branch_{branch} {}

    // Getters
    const std::string& getName() const { return name_; }
    const std::string& getCollegeName() const { return collegeName_; }
    const std::string& getBranch() const { return branch_; }
};

// Derived class
class BankDetails : public Customer {
private:
    std::string bankName_;
    std::string branchName_;
    std::string ifscCode_;
    int accountNumber_;
public:
    BankDetails(std::string_view name = "", std::string_view collegeName = "", std::string_view branch = "",
                std::string_view bankName = "", std::string_view branchName = "",
                std::string_view ifscCode = "", int accountNumber = 0)
        : Customer{name, collegeName, branch},
          bankName_{bankName}, branchName_{branchName},
          ifscCode_{ifscCode}, accountNumber_{accountNumber} {}

    const std::string& getBankName() const { return bankName_; }
    const std::string& getBranchName() const { return branchName_; }
    const std::string& getIfscCode() const { return ifscCode_; }
    int getAccountNumber() const { return accountNumber_; }
};

// Further derived class
class Amount : public BankDetails {
private:
    int amount_;
public:
    Amount(std::string_view name = "", std::string_view collegeName = "", std::string_view branch = "",
           std::string_view bankName = "", std::string_view branchName = "",
           std::string_view ifscCode = "", int accountNumber = 0, int amount = 0)
        : BankDetails{name, collegeName, branch, bankName, branchName, ifscCode, accountNumber},
          amount_{amount} {}

    int getAmount() const { return amount_; }
};

// Main function
int main() {
    Amount a1{"Shah", "IIT Patna", "Mechanical", "SBI", "Dostia", "SBIN0008384", 323231717, 54000};
    
    std::cout << "Name: " << a1.getName() << "\n";
    std::cout << "College: " << a1.getCollegeName() << "\n";
    std::cout << "Branch: " << a1.getBranch() << "\n";
    std::cout << "Bank: " << a1.getBankName() << "\n";
    std::cout << "Bank Branch: " << a1.getBranchName() << "\n";
    std::cout << "IFSC: " << a1.getIfscCode() << "\n";
    std::cout << "Account No: " << a1.getAccountNumber() << "\n";
    std::cout << "Amount: ₹" << a1.getAmount() << "\n";

    return 0;
}
