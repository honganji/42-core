#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
  private:
	Weapon *_weapon;
	std::string _name;

  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack(void);
	void setWeapon(Weapon &weapon);
};

#endif
