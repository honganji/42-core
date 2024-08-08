#ifndef CAT_H
#define CAT_H

#include "iostream"
#include "Animal.hpp"

class Cat : public Animal
{
	public:
	  Cat(void);
	  Cat(const Cat &t);
	  Cat &operator=(const Cat &t);
	  ~Cat(void);
	  void makeSound(void) const;
};

#endif
