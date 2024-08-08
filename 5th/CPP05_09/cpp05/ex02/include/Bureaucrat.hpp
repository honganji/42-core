#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "iostream"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	
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
		Bureaucrat(void);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat &operator=(const Bureaucrat &ref);
		~Bureaucrat(void);
		const std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(AForm &f);
		void executeForm(AForm const &f);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a);

#endif
