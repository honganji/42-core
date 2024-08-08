#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB " << _name << " was born. " << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destroy humanB " << _name << std::endl;
}
