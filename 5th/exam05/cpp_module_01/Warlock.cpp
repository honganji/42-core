#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) :
_name(name),
_title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock(void)
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName(void) const
{
	return (_name);
}
const std::string &Warlock::getTitle(void) const
{
	return (_title);
}
void Warlock::setTitle(const std::string &newTitle)
{
	_title = newTitle;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name <<", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
	if (it != _spellBook.end())
	{
		delete it->second;
		_spellBook.erase(it);
	}
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
	if (it != _spellBook.end())
		_spellBook[spellName]->launch(target);
}
