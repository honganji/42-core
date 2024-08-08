#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh(void)
{
}

Fwoosh *Fwoosh::clone(void) const
{
	return (new Fwoosh());
}
