#include "replace.hpp"

void Replace::_openFiles(void)
{
	_srcFile.open(_fileName);
	if (!_srcFile.is_open())
	{
		std::cerr << "There is something wrong when opening ";
		std::cerr << "\"" << _fileName << "\" file" << std::endl;
		_errorState = 1;
		return;
	}
	_fileName.append(".replace");
	_dstFile.open(_fileName);
	if (!_dstFile.is_open())
	{
		std::cerr << "There is something wrong when opening " << "\"";
		std::cerr << _fileName << "\" file" << std::endl;
		_errorState = 1;
		return;
	}
}

Replace::Replace(char **argv)
{
	_fileName = argv[1];
	_s1 = argv[2];
	_s2 = argv[3];
	_errorState = 0;
	_openFiles();
}

bool Replace::getErrorState(void)
{
	return (_errorState);
}

std::string Replace::_replaceLine(std::string line)
{
	size_t pos = 0;
	size_t lastPos = 0;
	std::string fixedLine;
	while ((pos = line.find(_s1, lastPos)) != std::string::npos)
	{
		if (pos != lastPos)
			fixedLine += line.substr(lastPos, pos - lastPos);
		fixedLine += _s2;
		lastPos = pos + _s1.length();
	}
	fixedLine += line.substr(lastPos);
	return (fixedLine);
}

void Replace::replaceStr(void)
{
	std::string line;

	while (getline(_srcFile, line))
	{
		_dstFile << _replaceLine(line) << std::endl;
	}
}
