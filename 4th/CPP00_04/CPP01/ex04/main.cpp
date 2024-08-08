#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		Replace replace(argv);
		if (replace.getErrorState())
			return (1);
		replace.replaceStr();
	}
	else
	{
		std::cout << "The number of arguments is not 3...";
		return (1);
	}
	return (0);
}
