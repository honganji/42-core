#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		const unsigned int _initEnergyPoints;
		const unsigned int _initAttackDamage;

	public:
	FragTrap(void);
	FragTrap(const std::string &name);
	~FragTrap();
	void highFivesGuys(void);
};
#endif
