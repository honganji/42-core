#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl(argc, argv);
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}
