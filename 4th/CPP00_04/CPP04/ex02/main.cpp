#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// Test AAnimal array
	{
		std::cout << "\033[32mTest AAnimal array\033[0m" << std::endl;
		std::cout << "\033[32m---------------------------\033[0m" << std::endl;
		AAnimal **animals;
		// This causes an error
		// AAnimal aAnimals();

		animals = new AAnimal *[10];
		for (int i = 0; i < 10; i++)
		{
			animals[i++] = new Dog;
			animals[i] = new Cat;
		}
		for (int i = 0; i < 10; i++)
			animals[i]->makeSound();
		for (int i = 0; i < 10; i++)
		{
			delete animals[i];
		}
		delete[] animals;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	return (0);
}
