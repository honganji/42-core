#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include "iostream"

class WrongAnimal
{
	protected:
	  std::string _type;
	
	public:
	  WrongAnimal(void);
	  WrongAnimal(const WrongAnimal &t);
	  WrongAnimal &operator=(const WrongAnimal &t);
	  ~WrongAnimal(void);
	  void makeSound(void) const;
	  std::string getType(void);
};

#endif
