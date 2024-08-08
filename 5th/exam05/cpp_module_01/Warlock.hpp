#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	protected:

	private:
	  std::string _name;
	  std::string _title;
	  std::map<std::string, ASpell *> _spellBook;

	public:
	  Warlock(std::string name, std::string title);
	  ~Warlock(void);
	  const std::string &getName(void) const;
	  const std::string &getTitle(void) const;
	  void setTitle(const std::string &newTitle);
	  void introduce() const;
	  void learnSpell(ASpell *spell);
	  void forgetSpell(std::string spellName);
	  void launchSpell(std::string spellName, ATarget &target);
};

#endif
