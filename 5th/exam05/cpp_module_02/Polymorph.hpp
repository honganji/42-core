#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
	protected:

	private:

	public:
	  Polymorph();
	  ~Polymorph(void);
	  Polymorph *clone(void) const;
};

#endif
