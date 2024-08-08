#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// Test deep copy
	{
		std::cout << "\033[32mTest deep copy\033[0m" << std::endl;
		std::cout << "\033[32m---------------------------\033[0m" << std::endl;
		Dog dog_src;
		Cat cat_src;
		Dog dog_copy;
		Cat cat_copy;
		{
			Dog dog_tmp = dog_src;
			dog_tmp.updateIdea("tmp idea", 0);
			std::cout << "tmp dog brain idea: " << dog_tmp.getIdea(0) << std::endl;
		}

		dog_src.updateIdea("original dog brain", 0);
		cat_src.updateIdea("original cat brain", 0);
		dog_copy = dog_src;
		cat_copy = cat_src;
		std::cout << "Before-----------------" << std::endl;
		std::cout << "Original dog brain idea: " << dog_src.getIdea(0) << std::endl;
		std::cout << "Copy dog brain idea: " << dog_copy.getIdea(0) << std::endl;
		std::cout << "Original cat brain idea: " << cat_src.getIdea(0) << std::endl;
		std::cout << "Copy cat brain idea: " << cat_copy.getIdea(0) << std::endl;
		std::cout << "-----------------------" << dog_src.getIdea(0) << std::endl << std::endl;
		dog_copy.updateIdea("copy dog brain", 0);
		cat_copy.updateIdea("copy cat brain", 0);

		std::cout << "After------------------" << std::endl;
		std::cout << "Original dog brain idea: " << dog_src.getIdea(0) << std::endl;
		std::cout << "Copy dog brain idea: " << dog_copy.getIdea(0) << std::endl;
		std::cout << "Original cat brain idea: " << cat_src.getIdea(0) << std::endl;
		std::cout << "Copy cat brain idea: " << cat_copy.getIdea(0) << std::endl;
		std::cout << "-----------------------" << dog_src.getIdea(0) << std::endl << std::endl;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl;
	
	// Test Animal array
	{
		std::cout << "\033[31mTest Animal array\033[0m" << std::endl;
		std::cout << "\033[31m---------------------------\033[0m" << std::endl;
		Animal **Animals;

		Animals = new Animal *[10];
		for (int i = 0; i < 10; i++)
		{
			Animals[i++] = new Dog;
			Animals[i] = new Cat;
		}
		for (int i = 0; i < 10; i++)
			Animals[i]->makeSound();
		for (int i = 0; i < 10; i++)
			delete Animals[i];
		delete[] Animals;
	}
	std::cout << "\033[31m---------------------------\033[0m" << std::endl;
	return (0);
}
