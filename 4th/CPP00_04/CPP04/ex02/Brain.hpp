#ifndef BRAIN_H
#define BRAIN_H

#include "iostream"

class Brain
{
	private:
	  std::string *ideas;
	public:
	  Brain(void);
	  Brain(Brain &t);
	  ~Brain(void);
	  void updateEle(std::string ele, int index);
	  std::string *getIdeas(void);
};

#endif
