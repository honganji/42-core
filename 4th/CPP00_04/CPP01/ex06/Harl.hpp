#ifndef HARL_H
#define HARL_H

#include <fstream>
#include <iostream>
#include <map>

class Harl
{
  public:
	Harl(int argc, char **argv);
	~Harl(void) {};
	void complain(std::string level);
	void changeOn(std::string level);

  private:
	typedef void (Harl::*CompFun)();
	struct FunPair
	{
		int _index;
		CompFun _compFun;
		FunPair(int index, CompFun compFun) : _index(index), _compFun(compFun)
		{
		}
	};
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
	std::map<std::string, FunPair> _compFuns;
	int _offIndex;
};

#endif
