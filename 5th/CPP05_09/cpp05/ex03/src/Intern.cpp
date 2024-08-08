#include "../include/Intern.hpp"

AForm *Intern::_makePPForm(std::string name)
{
	return (new PresidentialPardonForm(name));
}

AForm *Intern::_makeRRForm(std::string name)
{
	return (new RobotomyRequestForm(name));
}

AForm *Intern::_makeSCForm(std::string name)
{
	return (new ShrubberyCreationForm(name));
}

const Intern::Forms Intern::_forms[] = {
	{"robotomy request", &Intern::_makeRRForm},
	{"shrubbery creation", &Intern::_makeSCForm},
	{"presidential pardon", &Intern::_makePPForm}
};

Intern::Intern(void)
{
	std::cout << "create Intern instance!" << std::endl;
}

Intern &Intern::operator=(const Intern &ref)
{
	(void) ref;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "destroy intern" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string targetName)
{
	int size = sizeof(_forms) / sizeof(_forms[0]);

	for (int i = 0; i < size; i++)
		if (formName == _forms[i].formName)
			return (_forms[i].createForm(targetName));
	throw NotMatchFormException();
}
