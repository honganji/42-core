#ifndef ANIMAL_H
#define ANIMAL_H

#include "iostream"

class Animal
{
	protected:
	  std::string _type;
	
	public:
	  Animal(void);
	  Animal(const Animal &t);
	  Animal &operator=(const Animal &t);
	  virtual ~Animal(void);
	  virtual void makeSound();
	  std::string getType(void);
};

#endif
