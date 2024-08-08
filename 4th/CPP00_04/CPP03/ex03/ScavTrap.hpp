#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		const unsigned int _initHitPoints;

	public:
	ScavTrap(void);
	ScavTrap(const std::string &name);
	~ScavTrap();
	void guardGate(void);
	void attack(const std::string &target);
};
#endif