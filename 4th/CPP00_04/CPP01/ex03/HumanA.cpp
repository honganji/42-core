#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << _name << " was born. ";
	std::cout << "Armed with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destroy humanA " << _name << std::endl;
}
