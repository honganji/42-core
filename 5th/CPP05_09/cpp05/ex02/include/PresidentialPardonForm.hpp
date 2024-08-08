#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
		~PresidentialPardonForm(void);
		void pardon(void) const;
		void execute(Bureaucrat const &executor) const;
};

#endif
