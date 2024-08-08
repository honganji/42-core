#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// Test for each classes
	{
		std::cout << "\033[32mTest for each classes\033[0m" << std::endl;
		std::cout << "\033[32m---------------------------\033[0m" << std::endl;
		Animal *animal = new Animal();
		Animal *dog = new Dog();
		Animal *cat = new Cat();
		std::cout << "Animal type: " << animal->getType() << std::endl;
		animal->makeSound();
		std::cout << "Dog type: " << dog->getType() << std::endl;
		dog->makeSound();
		std::cout << "Cat type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete animal;
		delete dog;
		delete cat;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl << std::endl;

	// Test for wrong classes
	{
		std::cout << "\033[31mTest for wrong classes\033[0m" << std::endl;
		std::cout << "\033[31m---------------------------\033[0m" << std::endl;
		WrongAnimal *wrongAnimal = new WrongAnimal();
		WrongAnimal *wrongCat = new WrongCat();
		std::cout << "Wrong Animal type: " << wrongAnimal->getType() << std::endl;
		wrongAnimal->makeSound();
		std::cout << "Wrong Cat type: " << wrongCat->getType() << std::endl;
		wrongCat->makeSound();
		delete wrongAnimal;
		delete wrongCat;
	}
	std::cout << "\033[31m---------------------------\033[0m" << std::endl;
	return (0);
}
