#include "Zombie.hpp"

int main(void)
{
	int index = -1;
	int N = 4;
	Zombie *zombies = zombieHorde(N, "Toosu");
	while (++index < N)
		zombies[index].announce();
	delete[] zombies;
	return (0);
}
