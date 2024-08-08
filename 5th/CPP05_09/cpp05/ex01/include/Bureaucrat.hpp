#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "iostream"
#include "Form.hpp"

class Form;

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
		const std::string getName(void);
		int getGrade(void);
		void increment(void);
		void decrement(void);
		void signForm(Form &f);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a);

#endif
