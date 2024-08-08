#include "Weapon.hpp"

Weapon::Weapon(std::string initType)
{
	_type = initType;
}

Weapon::~Weapon(void)
{
	std::cout << "Destroy the weapon" << std::endl;
}

const std::string &Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(std::string newType)
{
	_type = newType;
}
