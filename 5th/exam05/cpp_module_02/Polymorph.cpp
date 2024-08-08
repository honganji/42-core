#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::~Polymorph(void)
{
}

Polymorph *Polymorph::clone(void) const
{
	return (new Polymorph());
}
