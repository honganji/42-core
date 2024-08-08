#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
	protected:

	private:

	public:
	  Fireball();
	  ~Fireball(void);
	  Fireball *clone(void) const;
};

#endif
