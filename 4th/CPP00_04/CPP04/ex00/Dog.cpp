#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Animal typed " << _type << " is created!" << std::endl;
}

Dog::Dog(const Dog &t)
{
	_type = t._type;
}

Dog &Dog::operator=(const Dog &t)
{
	if (this != &t)
		_type = t._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "bow bow bow" << std::endl;
}
