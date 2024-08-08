#ifndef FORM_H
# define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
	  Form(void);
	  Form(std::string name, int gradeSign, int gradeExe);
	  Form(const Form &ref);
	  Form &operator=(const Form &ref);
	  ~Form(void);
	  std::string getName(void) const;
	  int getGradeSign(void) const;
	  int getGradeExe(void) const;
	  bool getIsSigned(void) const;
	  void beSigned(Bureaucrat bc);
};

std::ostream &operator<<(std::ostream &o, Form &ref);
#endif
