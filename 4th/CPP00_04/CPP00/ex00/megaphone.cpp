#include <cctype>
#include <cstring>
#include <iostream>

bool check_if_empty(int argc, char **argv)
{
	argc--;
	while (argc > 0)
	{
		if (argv[argc--][0] != '\0')
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int chr_index = -1;
	int arg_index = 0;

	if (argc > 1 && !check_if_empty(argc, argv))
		while (++arg_index < argc)
		{
			while (argv[arg_index][++chr_index])
				std::cout << (char)toupper(argv[arg_index][chr_index]);
			chr_index = -1;
		}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
