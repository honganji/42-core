#include "Harl.hpp"

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
	std::map<std::string, CompFun> compFuns;
	compFuns["DEBUG"] = &Harl::_debug;
	compFuns["INFO"] = &Harl::_info;
	compFuns["WARNING"] = &Harl::_warning;
	compFuns["ERROR"] = &Harl::_error;
	std::map<std::string, CompFun>::iterator fun = compFuns.find(level);
	if (fun != compFuns.end())
		(this->*(fun->second))();
};
