#include "../include/AForm.hpp"

int AForm::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	return (grade);
}

AForm::AForm(void)
: _name("default_Aform"),
_gradeSign(10),
_gradeExe(15),
_isSigned(false)
{
	std::cout << "AForm " << _name << " is created!" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExe)
: _name(name),
_gradeSign(checkGrade(gradeSign)),
_gradeExe(checkGrade(gradeExe)),
_isSigned(false)
{
	std::cout << "AForm " << getName() << " is created!" << std::endl;
}

AForm::AForm(const AForm &ref)
: _name(ref.getName()),
_gradeSign(ref.getGradeExe()),
_gradeExe(ref.getGradeExe())
{
	_isSigned = ref.getIsSigned();
	
}

AForm &AForm::operator=(const AForm &ref)
{
	if (this != &ref)
		_isSigned = ref.getIsSigned();
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm " << getName() << " is destroyed" << std::endl;
}

std::string AForm::getName(void) const
{
	return (_name);
}

int AForm::getGradeSign() const
{
	return (_gradeSign);
}

int AForm::getGradeExe() const
{
	return (_gradeExe);
}

bool AForm::getIsSigned(void) const
{
	return (_isSigned);
}

void AForm::setIsSigned(bool newVal)
{
	_isSigned = newVal;
}

void AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > getGradeSign())
		throw GradeTooLowException();
	else
	{
		_isSigned = true;
		std::cout << "The AForm " << getName();
		std::cout << " is signed by " << bc.getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, AForm &ref)
{
	o << "AForm " << ref.getName() << std::endl;
	o << "sign grade: " << ref.getGradeSign() << std::endl;
	o << "exe grade: " << ref.getGradeExe() << std::endl;
	o << "is signed: " << ref.getIsSigned() << std::endl;
	return (o);
}

void AForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
}
