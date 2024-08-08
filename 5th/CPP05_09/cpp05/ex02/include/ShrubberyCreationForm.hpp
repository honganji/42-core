#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm(void);
		void createAsciiTree(void) const;
		void execute(Bureaucrat const &executor) const;
};

#endif
