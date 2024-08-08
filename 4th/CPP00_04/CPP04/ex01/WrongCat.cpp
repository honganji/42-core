#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "Wrong Animal typed " << _type << " is created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &t)
{
	_type = t._type;
}

WrongCat &WrongCat::operator=(const WrongCat &t)
{
	if (this != &t)
		_type = t._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed" << std::endl;
}
