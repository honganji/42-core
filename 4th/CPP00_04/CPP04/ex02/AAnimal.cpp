#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "AAnimal typed " << _type << " is created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &t)
{
	_type = t._type;
}

AAnimal &AAnimal::operator=(const AAnimal &t)
{
	if (this != &t)
		_type = t._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal typed " << _type << " is destroyed" << std::endl;
}

void AAnimal::makeSound()
{
	std::cout << "Ahhhhhhh" << std::endl;
}

std::string AAnimal::getType(void)
{
	return (_type);
}
