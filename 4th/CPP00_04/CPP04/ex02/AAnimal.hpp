#ifndef A_ANIMAL_H
#define A_ANIMAL_H

#include "iostream"

class AAnimal
{
	protected:
	  std::string _type;
	
	public:
	  AAnimal(void);
	  AAnimal(const AAnimal &t);
	  AAnimal &operator=(const AAnimal &t);
	  virtual ~AAnimal(void);
	  virtual void makeSound() = 0;
	  virtual std::string getType(void);
};

#endif
