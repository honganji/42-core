#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	// Test for each function
	{
		std::cout << "\033[32mClapTrap Test for each function\033[0m" << std::endl;
		std::cout << "\033[32m---------------------\033[0m" << std::endl;
		ClapTrap clapTrap("CrapTrap");
		std::cout << clapTrap << std::endl;
		clapTrap.attack("CrapTrap enemy");
		clapTrap.beRepaired(4);
		std::cout << clapTrap << std::endl;
		clapTrap.takeDamage(2);
		std::cout << clapTrap;
	}
	std::cout << "\033[32m---------------------\033[0m" << std::endl;

	// Test for beRepaired function when you try to repair more than the maximum of unsigned int
	{
		std::cout << std::endl << "\033[32mClapTrap Test for insane input for beRepaired function\033[0m" << std::endl;
		std::cout << "\033[32m---------------------\033[0m" << std::endl;
		ClapTrap clapTrap("CrapTrap");
		std::cout << clapTrap;
		clapTrap.beRepaired(std::numeric_limits<unsigned int>::max());
		std::cout << clapTrap;
	}
	std::cout << "\033[32m---------------------\033[0m" << std::endl;

	// Test for takeDamage function when you take damage more than the current hp
	{
		std::cout << std::endl << "\033[32mClapTrap Test for insane input for beRepaired function\033[0m" << std::endl;
		std::cout << "\033[32m---------------------\033[0m" << std::endl;
		ClapTrap clapTrap("CrapTrap");
		std::cout << clapTrap;
		clapTrap.takeDamage(std::numeric_limits<unsigned int>::max());
		std::cout << clapTrap;
	}
	std::cout << "\033[32m---------------------\033[0m" << std::endl;

	// Test for ScavTrap
	{
		std::cout << "\033[33mScavTrap Test\033[0m" << std::endl;
		std::cout << "\033[33m---------------------\033[0m" << std::endl;
		ScavTrap scavTrap("Scav");
		std::cout << std::endl << scavTrap;
		scavTrap.attack("ScavTrap enemy");
		std::cout << std::endl;
		scavTrap.beRepaired(4);
		std::cout << scavTrap << std::endl;
		scavTrap.takeDamage(10);
		std::cout << scavTrap << std::endl;
		scavTrap.guardGate();
	}
	std::cout << "\033[33m---------------------\033[0m" << std::endl << std::endl;

	// Test for FragTrap
	{
		std::cout << "\033[35mFragTrap Test\033[0m" << std::endl;
		std::cout << "\033[35m---------------------\033[0m" << std::endl;
		FragTrap fragTrap("Scav");
		std::cout << std::endl << fragTrap;
		fragTrap.attack("FragTrap enemy");
		std::cout << std::endl;
		fragTrap.beRepaired(4);
		std::cout << fragTrap << std::endl;
		fragTrap.takeDamage(10);
		std::cout << fragTrap << std::endl;
		fragTrap.highFivesGuys();
	}
	std::cout << "\033[35m---------------------\033[0m" << std::endl << std::endl;
	return (0);
}
