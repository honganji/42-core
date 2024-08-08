#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Wrong Animal")
{
	std::cout << "Wrong Animal typed " << _type << " is created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &t)
{
	_type = t._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &t)
{
	if (this != &t)
		_type = t._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal typed " << _type << " is destroyed" << std::endl;
}

void WrongAnimal::makeSound()
{
	std::cout << "wroooooong" << std::endl;
}
std::string WrongAnimal::getType(void)
{
	return (_type);
}
