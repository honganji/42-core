#ifndef A_FORM_H
# define A_FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	  const std::string _name;
	  const int _gradeSign;
	  const int _gradeExe;
	  bool _isSigned;
	  int checkGrade(int grade);

	public:
	  class GradeTooHighException : public std::exception
	  {
		const char *what() const throw()
		{
			return ("Grade is too high");
		}
	  };
	  class GradeTooLowException : public std::exception
	  {
		const char *what() const throw()
		{
			return ("Grade is too low");
		}
	  };
	  class IsNotSigned : public std::exception
	  {
		const char *what() const throw()
		{
			return ("The form is not signed!");
		}
	  };
	  AForm(void);
	  AForm(std::string name, int gradeSign, int gradeExe);
	  AForm(const AForm &ref);
	  AForm &operator=(const AForm &ref);
	  virtual ~AForm(void);
	  std::string getName(void) const;
	  int getGradeSign(void) const;
	  int getGradeExe(void) const;
	  bool getIsSigned(void) const;
	  void setIsSigned(bool newVal);
	  void beSigned(Bureaucrat &bc);
	  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm &ref);
#endif
