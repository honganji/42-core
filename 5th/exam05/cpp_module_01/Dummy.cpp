#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy(void)
{
}

Dummy *Dummy::clone(void) const
{
	return (new Dummy());
}
