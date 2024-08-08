#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "iostream"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	  WrongCat(void);
	  WrongCat(const WrongCat &t);
	  WrongCat &operator=(const WrongCat &t);
	  ~WrongCat(void);
};

#endif
