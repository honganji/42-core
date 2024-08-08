#ifndef CRAP_TRAP_H
#define CRAP_TRAP_H

#include "iostream"
#include "limits"

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	bool _check(void);

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &t);
	ClapTrap &operator=(const ClapTrap &t);
	~ClapTrap(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int getHP(void);
	unsigned int getEP(void);
	unsigned int getAD(void);
};

std::ostream &operator<<(std::ostream &o, ClapTrap &c);
#endif
