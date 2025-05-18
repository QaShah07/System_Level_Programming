#infndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include<string>

class ClapTrap{
private:
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int attackDamage_;
public:
	ClapTrap(); // construcotr par default
	ClapTrap(const std::string &name); // constructor parameter
	ClapTrap(const ClapTrap&source); // Operator dafectt
	virtual ~ClapTrap(); // destructor


	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);


	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getAttackDamage() const;
	unsigned int getEnergyPoints() const;

};
#endif
