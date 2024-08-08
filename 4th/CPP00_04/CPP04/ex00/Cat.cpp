#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	_type = "Cat";
	std::cout << "Animal typed " << _type << " is created!" << std::endl;
}

Cat::Cat(const Cat &t)
{
	_type = t._type;
}

Cat &Cat::operator=(const Cat &t)
{
	if (this != &t)
		_type = t._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "maw maw maw" << std::endl;
}
