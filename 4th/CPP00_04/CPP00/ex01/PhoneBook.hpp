#ifndef PhoneBook_H
#define PhoneBook_H

#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;
	int get_min_index(void);
	int get_arr_index(int ele_index);
	void display_all(void);

  public:
	PhoneBook()
	{
		index = 0;
	};
	~PhoneBook() {};
	void add(void);
	void search(void);
	void display_info(int ele_index);
};

#endif
