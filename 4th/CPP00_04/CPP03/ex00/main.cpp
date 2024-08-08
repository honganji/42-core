#include "ClapTrap.hpp"

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
	return (0);
}
