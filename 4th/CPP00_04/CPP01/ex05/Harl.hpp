#ifndef HARL_H
#define HARL_H

#include <fstream>
#include <iostream>
#include <map>

class Harl
{
  private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
	typedef void (Harl::*CompFun)();

  public:
	Harl(void) {};
	~Harl(void) {};
	void complain(std::string level);
};

#endif
