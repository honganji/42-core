#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Animal typed " << _type << " is created!" << std::endl;
}

Cat::Cat(const Cat &t)
{
	_type = t._type;
	if (t._brain)
		_brain = new Brain(*t._brain);
	else
		_brain = nullptr;
}

Cat &Cat::operator=(const Cat &t)
{
	if (this != &t)
	{
		AAnimal::operator=(t);
		delete _brain;
		if (t._brain)
			_brain = new Brain(*t._brain);
		else
			_brain = nullptr;
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "maw maw maw" << std::endl;
}

std::string Cat::getType(void)
{
	return (_type); 
}

void Cat::updateIdea(std::string ele, int index)
{
	_brain->updateEle(ele, index);
}

std::string Cat::getIdea(int index)
{
	return (_brain->getIdeas()[index]);
}
