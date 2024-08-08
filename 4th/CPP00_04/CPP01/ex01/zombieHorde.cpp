#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int index = -1;
	Zombie *zombies = new Zombie[N];

	while (++index < N)
		zombies[index].setName(name);
	return (zombies);
}
