#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	_name = "DiamondTrap";
	_hitPoints = FragTrap::_initEnergyPoints;
	_energyPoints = ScavTrap::_initHitPoints;
	_attackDamage = FragTrap::_initAttackDamage;
	std::cout << "DiamondTrap constructor is called and the name is ";
	std::cout << "initialized as " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor is called and the name is ";
	std::cout << "initialized as " << _name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap instance " << _name << " is destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::getEP()
{
	std::cout << "DiamondTrap ep: "<< _energyPoints << std::endl;
}
