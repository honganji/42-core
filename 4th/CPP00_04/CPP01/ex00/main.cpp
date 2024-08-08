#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("Yuji");
	zombie->announce();
	delete zombie;
	randomChump("Sukuna");
	return (0);
}
