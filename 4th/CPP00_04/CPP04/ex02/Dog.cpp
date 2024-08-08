#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Animal typed " << _type << " is created!" << std::endl;
}

Dog::Dog(const Dog &t)
{
	_type = t._type;
	if (t._brain)
		_brain = new Brain(*t._brain);
	else
		_brain = nullptr;
}

Dog &Dog::operator=(const Dog &t)
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

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "bow bow bow" << std::endl;
}

std::string Dog::getType(void)
{
	return (_type); 
}

void Dog::updateIdea(std::string ele, int index)
{
	_brain->updateEle(ele, index);
}

std::string Dog::getIdea(int index)
{
	return (_brain->getIdeas()[index]);
}
