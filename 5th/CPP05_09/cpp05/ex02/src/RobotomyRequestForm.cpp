#include "../include/RobotomyRequestForm.hpp"

int RobotomyRequestForm::prob = 0;

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("robotomy request form", 72, 45)
{
	std::cout << "RobotomyRequestForm ";
	std::cout << getName();
	std::cout << " instance is initialized";
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) :
AForm(name, 72, 45)
{
	std::cout << "RobotomyRequestForm ";
	std::cout << getName();
	std::cout << " instance is initialized";
	std::cout << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	if (this != &ref)
		setIsSigned(ref.getIsSigned());
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) :
AForm()
{
	setIsSigned(ref.getIsSigned());
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm instance ";
	std::cout << getName() << " is destroyed";
	std::cout << std::endl;
}

void RobotomyRequestForm::tryRobotomize(void) const
{
	prob++;
	if (prob % 2)
	{
		std::cout << "DRUUUUUUUUUUUU" << std::endl;
		std::cout << "The target " << getName();
		std::cout << " is successfully robotomized!!" << std::endl;
	}
	else
	{
		std::cout << "The target " << getName();
		std::cout << " failed to be robotomized unfortunately" << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw IsNotSigned();
	if (executor.getGrade() > getGradeExe())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	tryRobotomize();
}
