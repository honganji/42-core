#include "../include/Form.hpp"

int Form::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	return (grade);
}

Form::Form(void)
: _name("default_form"),
_gradeSign(10),
_gradeExe(15),
_isSigned(false)
{
	std::cout << "Form " << _name << " is created!" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExe)
: _name(name),
_gradeSign(checkGrade(gradeSign)),
_gradeExe(checkGrade(gradeExe)),
_isSigned(false)
{
	std::cout << "Form " << getName() << "is created!" << std::endl;
}

Form::Form(const Form &ref)
: _name(ref.getName()),
_gradeSign(ref.getGradeExe()),
_gradeExe(ref.getGradeExe())
{
	_isSigned = ref.getIsSigned();
	
}

Form &Form::operator=(const Form &ref)
{
	if (this != &ref)
		_isSigned = ref.getIsSigned();
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form " << getName() << " is destroyed" << std::endl;
}

std::string Form::getName(void) const
{
	return (_name);
}

int Form::getGradeSign() const
{
	return (_gradeSign);
}

int Form::getGradeExe() const
{
	return (_gradeExe);
}

bool Form::getIsSigned(void) const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat bc)
{
	if (bc.getGrade() > getGradeSign())
		throw GradeTooLowException();
	else
	{
		_isSigned = true;
		std::cout << "The Form " << getName();
		std::cout << " is signed by " << bc.getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Form &ref)
{
	o << "Form " << ref.getName() << std::endl;
	o << "sign grade: " << ref.getGradeSign() << std::endl;
	o << "exe grade: " << ref.getGradeExe() << std::endl;
	o << "is signed: " << ref.getIsSigned() << std::endl;
	return (o);
}
