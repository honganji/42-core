#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	protected:

	private:

	public:
	  Fwoosh();
	  ~Fwoosh(void);
	  Fwoosh *clone(void) const;
};

#endif
