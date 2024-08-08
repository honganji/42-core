#ifndef A_TARGET_HPP
#define A_TARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:

	private:
	  std::string _type;

	public:
	  ATarget(std::string type);
	  virtual ~ATarget(void);
	  const std::string &getType(void) const;
	  virtual ATarget *clone(void) const = 0;
	  void getHitBySpell(const ASpell &spell) const;
};

#endif
