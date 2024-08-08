#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("CrapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor is called and the name is ";
	std::cout << "initialized as " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor is called and the name is ";
	std::cout << "initialized as " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &t)
{
	_name = t._name;
	_hitPoints = t._hitPoints;
	_energyPoints = t._energyPoints;
	_attackDamage = t._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &t)
{
	if (this != &t)
	{
		_name = t._name;
		_hitPoints = t._hitPoints;
		_energyPoints = t._energyPoints;
		_attackDamage = t._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap instance " << _name << " is destroyed!" << std::endl;
}

bool ClapTrap::_check(void)
{
	if (!_energyPoints)
	{
		std::cout << "You don't have any energy!" << std::endl;
		return (false);
	}
	if (!_hitPoints)
	{
		std::cout << "You don't have any hit points! Repair it!" << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string &target)
{
	if (!_check())
		return;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " is attacked ";
	std::cout << amount << " points of damage!" << std::endl;
	if (_hitPoints < amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "current hp is " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_check())
		return;
	_energyPoints--;
	std::cout << "hp is repaired by " << amount << std::endl;
	if (std::numeric_limits<unsigned int>::max() - amount < _hitPoints)
		_hitPoints = std::numeric_limits<unsigned int>::max();
	else
		_hitPoints += amount;
	std::cout << "current hp is " << _hitPoints << std::endl;
}

unsigned int ClapTrap::getHP(void)
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEP(void)
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAD(void)
{
	return (_attackDamage);
}

std::ostream &operator<<(std::ostream &o, ClapTrap &c)
{
	o << "Hit Points: " << c.getHP() << ", ";
	o << "Energy Points: " << c.getEP() << ", ";
	o << "Attack Damage: " << c.getAD() << std::endl;
	return (o);
}
