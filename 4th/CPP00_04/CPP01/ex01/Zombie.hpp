#ifndef Zombie_H
#define Zombie_H

#include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
