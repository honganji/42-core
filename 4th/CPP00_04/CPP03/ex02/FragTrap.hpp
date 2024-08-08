#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	FragTrap(void);
	FragTrap(const std::string &name);
	~FragTrap();
	void highFivesGuys(void);
};
#endif
