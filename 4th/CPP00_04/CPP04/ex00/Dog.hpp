#ifndef DOG_H
#define DOG_H

#include "iostream"
#include "Animal.hpp"

class Dog : public Animal
{
	public:
	  Dog(void);
	  Dog(const Dog &t);
	  Dog &operator=(const Dog &t);
	  ~Dog(void);
	  void makeSound(void) const;
};

#endif
