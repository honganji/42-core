#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Yuji"), _grade(1)
{
	std::cout << "Bureaucat " << _name << " is created!" << std::endl;
	std::cout << "Initialized grade is " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("Yuji")
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "Bureaucat " << _name << " is created!" << std::endl;
	std::cout << "Initialized grade is " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name("Yuji")
{
	_grade = ref._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		_grade = ref._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucat " << _name << " is destroyed" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increment(void)
{
	if (_grade + 1 > 150)
		throw GradeTooHighException();
	else
		_grade++;
}

void Bureaucrat::decrement(void)
{
	if (_grade - 1 < 1)
		throw GradeTooLowException();
	else
		_grade--;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Signer '" << getName() << "'";
		std::cout << " couldn't sign";
		std::cout << " Form " << f.getName();
		std::cout << " because signer '" << getName() << "'";
		std::cout << " grade(" << getGrade() << ")";
		std::cout << " is lower then form sign grade(" << f.getGradeSign();
		std::cout << ")" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &f)
{
	try
	{
		f.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		if (dynamic_cast<const GradeTooLowException*>(&e))
		{
			std::cout << "Signer '" << getName() << "'";
			std::cout << " couldn't execute";
			std::cout << " Form " << f.getName();
			std::cout << " because signer '" << getName() << "'";
			std::cout << " grade(" << getGrade() << ")";
			std::cout << " is lower then form sign grade(" << f.getGradeSign();
			std::cout << ")" << std::endl;
		}
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << "Bureaucrat " << a.getName() << ", grade: " << a.getGrade() << std::endl;
	return (o);
}
