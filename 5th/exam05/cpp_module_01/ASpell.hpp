#ifndef A_SPELL_HPP
#define A_SPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:

	private:
	  std::string _name;
	  std::string _effects;

	public:
	  ASpell(std::string name, std::string effects);
	  virtual ~ASpell(void);
	  std::string getName(void) const;
	  std::string getEffects(void) const;
	  virtual ASpell *clone(void) const = 0;
	  void launch(const ATarget &target) const;
};

#endif
