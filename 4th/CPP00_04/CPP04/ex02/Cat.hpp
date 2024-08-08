#ifndef CAT_H
#define CAT_H

#include "iostream"
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
	  Brain *_brain;

	public:
	  Cat(void);
	  Cat(const Cat &t);
	  Cat &operator=(const Cat &t);
	  ~Cat(void);
	  void makeSound();
	  std::string getType(void);
	  void updateIdea(std::string ele, int index);
	  std::string getIdea(int index);
};

#endif
