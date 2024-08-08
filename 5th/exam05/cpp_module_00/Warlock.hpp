#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
	protected:

	private:
	  std::string _name;
	  std::string _title;

	public:
	  Warlock(std::string name, std::string title);
	  ~Warlock(void);
	  const std::string &getName(void) const;
	  const std::string &getTitle(void) const;
	  void setTitle(const std::string &newTitle);
	  void introduce() const;
};

#endif
