#include "PhoneBook.hpp"

void PhoneBook::add(void)
{
	int num;

	num = get_min_index();
	std::cout << " " << std::string(43, '-') << " " << std::endl;
	contacts[num].initialize(index);
	index++;
}

void PhoneBook::search(void)
{
	std::string str_num;
	int num;

	display_all();
	std::cout << " " << std::string(43, '-') << " " << std::endl;
	std::cout << "Index: ";
	getline(std::cin, str_num);
	try
	{
		num = std::stoi(str_num);
		if (num < 0)
		{
			std::cout << "The number is less than 0" << std::endl;
			return;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	display_info(num);
}

int PhoneBook::get_min_index(void)
{
	int min_index;
	int count;

	min_index = 0;
	count = 0;
	if (index < 8)
		return (index);
	min_index = contacts[count].get_index();
	while (++count < 8)
	{
		if (contacts[count].get_index() < min_index)
			min_index = contacts[count].get_index();
	}
	count = -1;
	while (++count < 8)
	{
		if (contacts[count].get_index() == min_index)
			return (count);
	}
	return (0);
}

int PhoneBook::get_arr_index(int ele_index)
{
	int arr_index;
	int count;

	arr_index = -1;
	count = -1;
	while (++count < 8)
	{
		if (contacts[count].get_index() == ele_index)
			return (count);
	}
	return (-1);
}

void PhoneBook::display_info(int ele_index)
{
	int arr_index;

	arr_index = get_arr_index(ele_index);
	if (arr_index >= 0 && arr_index <= 7)
		contacts[arr_index].display_all_props();
	else
		std::cout << "There is no contact..." << std::endl;
}

void PhoneBook::display_all(void)
{
	int arr_index;

	arr_index = -1;
	std::cout << " " << std::string(43, '-') << " " << std::endl;
	std::cout << "|";
	std::cout << "     Index|";
	std::cout << "First Name|";
	std::cout << " Last Name|";
	std::cout << "  Nickname|" << std::endl;
	std::cout << "|" << std::string(10, '-');
	std::cout << "|" << std::string(10, '-');
	std::cout << "|" << std::string(10, '-');
	std::cout << "|" << std::string(10, '-');
	std::cout << "|" << std::endl;
	while (++arr_index < 8)
		contacts[arr_index].display_props();
}
