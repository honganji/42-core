#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal typed " << _type << " is created!" << std::endl;
}

Animal::Animal(const Animal &t)
{
	_type = t._type;
}

Animal &Animal::operator=(const Animal &t)
{
	if (this != &t)
		_type = t._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal typed " << _type << " is destroyed" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "Ahhhhhhh" << std::endl;
}

std::string Animal::getType(void)
{
	return (_type);
}
