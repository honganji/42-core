#ifndef WRONG_Animal_H
#define WRONG_Animal_H

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
	  void makeSound();
	  std::string getType(void);
};

#endif
