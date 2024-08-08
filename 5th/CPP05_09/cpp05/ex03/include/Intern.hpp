#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
	  class NotMatchFormException : public std::exception
	  {
		const char *what() const throw()
	  	{
			return ("No form matches the name...");
		}
	  };
	  struct Forms
	  {
		  std::string formName;
		  AForm *(*createForm)(std::string);
	  };
	  Intern(void);
	  Intern(const Intern &ref) {(void) ref;};
	  Intern &operator=(const Intern &ref);
	  ~Intern(void);
	  AForm *makeForm(std::string formName, std::string targetName);

	private:
	  static const Forms _forms[];
	  static AForm *_makePPForm(std::string name);
	  static AForm *_makeRRForm(std::string name);
	  static AForm *_makeSCForm(std::string name);
};

#endif
