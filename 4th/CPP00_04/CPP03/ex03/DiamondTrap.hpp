#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	  std::string _name;

	public:
	  DiamondTrap(void);
	  DiamondTrap(const std::string &name);
	  ~DiamondTrap();
	  void attack(const std::string &target);
	  void whoAmI();
	  void getEP();
};

#endif
