#ifndef CONTACT_H
#define CONTACT_H

#include <algorithm>
#include <iostream>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
	int index;
	void get_input(std::string name, std::string &prop);
	void get_phone_number(void);
	int check_phone_number(std::string num);
	void display_one_prop(std::string prop);

  public:
	Contact()
	{
		index = -1;
	};
	~Contact() {};
	void initialize(int index);
	void display_props(void);
	int get_index(void);
	void display_all_props(void);
};

#endif
