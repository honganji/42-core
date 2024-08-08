#ifndef DOG_H
#define DOG_H

#include "iostream"
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
	  Brain *_brain;
	
	public:
	  Dog(void);
	  Dog(const Dog &t);
	  Dog &operator=(const Dog &t);
	  ~Dog(void);
	  void makeSound();
	  void updateIdea(std::string ele, int index);
	  std::string getIdea(int index);
};

#endif
