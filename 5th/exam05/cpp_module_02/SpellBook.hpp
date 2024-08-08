#ifndef SPELL_BOOK_HPP
#define SPELL_BOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	protected:

	private:
	  std::map<std::string, ASpell *> _spellBook;
	public:
	  SpellBook();
	  ~SpellBook(void);
	  void learnSpell(ASpell *spell);
	  void forgetSpell(std::string const &spellName);
	  ASpell *createSpell(std::string const &spellName);
};

#endif
