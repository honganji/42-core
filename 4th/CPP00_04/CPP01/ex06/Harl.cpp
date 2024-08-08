#include "Harl.hpp"

Harl::Harl(int argc, char **argv)
{
	_offIndex = 0;
	_compFuns.insert(std::make_pair("DEBUG", FunPair(1, &Harl::_debug)));
	_compFuns.insert(std::make_pair("INFO", FunPair(2, &Harl::_info)));
	_compFuns.insert(std::make_pair("WARNING", FunPair(3, &Harl::_warning)));
	_compFuns.insert(std::make_pair("ERROR", FunPair(4, &Harl::_error)));
	if (argc == 2)
		changeOn(argv[1]);
}

void Harl::_debug(void)
{
	std::cout << "[DEBUG]  ";
	std::cout << "I love having extra bacon for ";
	std::cout << "my 7XL-double-cheese-triple-pickle-specialketchup";
	std::cout << "burger. I really do!" << std::endl;
}
void Harl::_info(void)
{
	std::cout << "\033[0;34m";
	std::cout << "[INFO]  ";
	std::cout << "\033[0;0m";
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
}
void Harl::_warning(void)
{
	std::cout << "\033[0;35m";
	std::cout << "[WARNING]  ";
	std::cout << "\033[0;0m";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here ";
	std::cout << "since last month." << std::endl;
}
void Harl::_error(void)
{
	std::cout << "\033[0;31m";
	std::cout << "[ERROR]  ";
	std::cout << "\033[0;0m";
	std::cout << "This is unacceptable! I want to speak to the manager now";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	std::map<std::string, FunPair>::iterator fun = _compFuns.find(level);
	if (fun != _compFuns.end() && _offIndex <= fun->second._index)
		(this->*(fun->second)._compFun)();
};

void Harl::changeOn(std::string level)
{
	std::map<std::string, FunPair>::iterator fun = _compFuns.find(level);
	if (fun != _compFuns.end())
		_offIndex = fun->second._index;
};
