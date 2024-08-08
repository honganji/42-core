#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	protected:

	private:

	public:
	  Dummy();
	  ~Dummy(void);
	  Dummy *clone(void) const;
};

#endif
