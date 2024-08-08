#ifndef BRICK_WALL_HPP
#define BRICK_WALL_HPP

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	protected:

	private:

	public:
	  BrickWall();
	  ~BrickWall(void);
	  BrickWall *clone(void) const;
};

#endif
