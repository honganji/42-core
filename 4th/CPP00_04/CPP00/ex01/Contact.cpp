#include "Contact.hpp"

void Contact::get_input(std::string name, std::string &prop)
{
	std::string str;

	std::cout << name << ": ";
	getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "The field cannot be empty!" << std::endl;
		get_input(name, prop);
	}
	else
		prop = str;
}

int Contact::check_phone_number(std::string num)
{
	if (num.empty())
	{
		std::cout << "The field cannot be empty!" << std::endl;
		return (0);
	}
	if (!std::all_of(num.begin(), num.end(), ::isdigit))
	{
		std::cout << "There is a character..." << std::endl;
		return (0);
	}
	if (num.length() > 15)
	{
		std::cout << "The length of number is too long" << std::endl;
		return (0);
	}
	return (1);
}

void Contact::get_phone_number(void)
{
	std::string num;
	std::cout << "phone number" << ": ";
	getline(std::cin, num);
	if (!check_phone_number(num))
	{
		get_phone_number();
		return;
	}
	phone_number = num;
}

void Contact::initialize(int cur_index)
{
	std::cout << "Type information please..." << std::endl;
	get_input("first name", first_name);
	get_input("last name", last_name);
	get_input("nickname", nick_name);
	get_phone_number();
	get_input("darkest secret", darkest_secret);
	index = cur_index;
}

void Contact::display_one_prop(std::string prop)
{
	int count;

	if (prop.length() < 10)
	{
		count = 10 - prop.length();
		while (count--)
			std::cout << " ";
		std::cout << prop;
	}
	else
		std::cout << prop.substr(0, 9) << ".";
}

void Contact::display_props(void)
{
	std::cout << "|";
	if (index == -1)
		display_one_prop("");
	else
		display_one_prop(std::to_string(index));
	std::cout << "|";
	display_one_prop(first_name);
	std::cout << "|";
	display_one_prop(last_name);
	std::cout << "|";
	display_one_prop(nick_name);
	std::cout << "|";
	std::cout << std::endl;
}

void Contact::display_all_props(void)
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nick_name << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

int Contact::get_index(void)
{
	return (index);
}