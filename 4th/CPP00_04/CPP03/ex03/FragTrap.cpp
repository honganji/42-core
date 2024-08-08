#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
ClapTrap(),
_initEnergyPoints(100),
_initAttackDamage(30)
{
	_name = "Frag";
	_hitPoints = 100,
	_energyPoints = 100,
	_attackDamage = 30,
	std::cout << "FragTrap constructor is called and the name is ";
	std::cout << "initialized as " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) :
ClapTrap(name),
_initEnergyPoints(100),
_initAttackDamage(30)
{
	_hitPoints = 100,
	_energyPoints = 100,
	_attackDamage = 30,
	std::cout << "FragTrap constructor is called and the name is ";
	std::cout << "initialized as " << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap instance " << _name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "✋✋✋✋✋✋✋✋✋✋✋✋✋✋✋✋✋" << std::endl;
}
