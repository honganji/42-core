#ifndef REPLACE_H
#define REPLACE_H

#include <fstream>
#include <iostream>

class Replace
{
  private:
	std::string _fileName;
	std::string _s1;
	std::string _s2;
	std::ifstream _srcFile;
	std::ofstream _dstFile;
	bool _errorState;
	void _openFiles(void);
	std::string _replaceLine(std::string line);

  public:
	Replace(char **argv);
	~Replace() {};
	bool getErrorState(void);
	void replaceStr(void);
};

#endif
