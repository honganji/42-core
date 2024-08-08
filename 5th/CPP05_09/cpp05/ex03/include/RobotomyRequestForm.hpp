#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	  static int prob;

	public:
	  RobotomyRequestForm(void);
	  RobotomyRequestForm(std::string name);
	  RobotomyRequestForm(const RobotomyRequestForm &ref);
	  RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
	  ~RobotomyRequestForm(void);
	  void tryRobotomize(void) const;
	  void execute(Bureaucrat const &executor) const;
};

#endif
