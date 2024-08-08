#include "Brain.hpp"

Brain::Brain(void)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = "brain";
	std::cout << "A new brain is created!" << std::endl;
}

Brain::~Brain(void)
{
	delete[] ideas;
	std::cout << "A brain is destroyed" << std::endl;
}

Brain::Brain(Brain &t)
{
	std::string *originalIdeas;

	originalIdeas = t.getIdeas();
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = originalIdeas[i];
}

void Brain::updateEle(std::string ele, int index)
{
	ideas[index] = ele;
}

std::string *Brain::getIdeas(void)
{
	return (ideas);
}
