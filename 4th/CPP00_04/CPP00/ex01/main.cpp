#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void wait_input(PhoneBook pb)
{
	std::string input;

	std::cout << " " << std::string(43, '-') << " " << std::endl;
	std::cout << "ADD -> Add a new contact" << std::endl;
	std::cout << "SEARCH -> Search for info" << std::endl;
	std::cout << "EXIT -> Finish this service" << std::endl;
	std::cout << " " << std::string(43, '-') << " " << std::endl;
	while (1)
	{
		std::cout << "Type command: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			exit(0);
	}
}

int main(void)
{
	PhoneBook pb;
	wait_input(pb);
	return (0);
}
