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
	else
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

const std::string Bureaucrat::getName(void)
{
	return (_name);
}

int Bureaucrat::getGrade(void)
{
	return (_grade);
}

void Bureaucrat::decrement(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::increment(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << "Bureaucrat " << a.getName() << ", grade: " << a.getGrade() << std::endl;
	return (o);
}
