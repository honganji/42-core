#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("presidential pardon form", 25, 5)
{
	std::cout << "PresidentialPardonForm ";
	std::cout << getName();
	std::cout << " instance is initialized";
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) :
AForm(name, 25, 5)
{
	std::cout << "PresidentialPardonForm ";
	std::cout << getName();
	std::cout << " instance is initialized";
	std::cout << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this != &ref)
		setIsSigned(ref.getIsSigned());
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) :
AForm()
{
	setIsSigned(ref.getIsSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm instance ";
	std::cout << getName() << " is destroyed";
	std::cout << std::endl;
}

void PresidentialPardonForm::pardon(void) const
{
	std::cout << "Zaphod Beeblebrox said '" << "Pardon " << getName();
	std::cout << "'?" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw IsNotSigned();
	if (executor.getGrade() > getGradeExe())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	pardon();
}
