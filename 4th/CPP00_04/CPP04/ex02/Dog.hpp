#ifndef DOG_H
#define DOG_H

#include "iostream"
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
	  Brain *_brain;
	
	public:
	  Dog(void);
	  Dog(const Dog &t);
	  Dog &operator=(const Dog &t);
	  ~Dog(void);
	  void makeSound(void);
	  std::string getType(void);
	  void updateIdea(std::string ele, int index);
	  std::string getIdea(int index);
};

#endif
