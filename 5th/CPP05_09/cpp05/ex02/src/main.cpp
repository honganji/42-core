#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	// Test for ShrubberyCreationForm
	{
		std::cout << "\033[31mTest for ShrubberyCreationForm\033[0m" << std::endl;
		std::cout << "\033[31m----------------------------------\033[0m" << std::endl;
		ShrubberyCreationForm shrubberyCreationForm1;
		ShrubberyCreationForm shrubberyCreationForm2("home");
		Bureaucrat bureaucrat;
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		bureaucrat.executeForm(shrubberyCreationForm1);
		bureaucrat.signForm(shrubberyCreationForm1);
		bureaucrat.executeForm(shrubberyCreationForm1);
		bureaucrat.executeForm(shrubberyCreationForm1);
		bureaucrat.executeForm(shrubberyCreationForm1);
		
		std::cout << "------------------------------" << std::endl << std::endl;
		std::cout << "shrubbery creation form test for " << shrubberyCreationForm2.getName();
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		bureaucrat.executeForm(shrubberyCreationForm2);
		bureaucrat.signForm(shrubberyCreationForm2);
		bureaucrat.executeForm(shrubberyCreationForm2);
		bureaucrat.executeForm(shrubberyCreationForm2);
		std::cout << "------------------------------" << std::endl;
	}
	std::cout << "\033[31m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for RobotomyRequestForm
	{
		std::cout << "\033[32mTest for RobotomyRequestForm\033[0m" << std::endl;
		std::cout << "\033[32m----------------------------------\033[0m" << std::endl;
		RobotomyRequestForm robotomyRequestForm1;
		RobotomyRequestForm robotomyRequestForm2("home");
		Bureaucrat bureaucrat(150);
		std::cout << std::endl;
		std::cout << "robotomize test for " << robotomyRequestForm1.getName();
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		// robotomyRequestForm1.tryRobotomize();
		bureaucrat.executeForm(robotomyRequestForm1);
		bureaucrat.signForm(robotomyRequestForm1);
		bureaucrat.executeForm(robotomyRequestForm1);
		bureaucrat.executeForm(robotomyRequestForm1);
		bureaucrat.executeForm(robotomyRequestForm1);
		
		std::cout << "------------------------------" << std::endl << std::endl;
		std::cout << "robotomize test for " << robotomyRequestForm2.getName();
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		bureaucrat.executeForm(robotomyRequestForm2);
		bureaucrat.signForm(robotomyRequestForm2);
		bureaucrat.executeForm(robotomyRequestForm2);
		bureaucrat.executeForm(robotomyRequestForm2);
		std::cout << "------------------------------" << std::endl;
	}
	std::cout << "\033[32m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for RobotomyRequestForm
	{
		std::cout << "\033[33mTest for RobotomyRequestForm\033[0m" << std::endl;
		std::cout << "\033[33m----------------------------------\033[0m" << std::endl;
		PresidentialPardonForm presidentialPardonForm1;
		PresidentialPardonForm presidentialPardonForm2("home");
		Bureaucrat bureaucrat;
		std::cout << std::endl;
		std::cout << "presidential pardon form test for " << presidentialPardonForm1.getName();
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		bureaucrat.executeForm(presidentialPardonForm1);
		bureaucrat.signForm(presidentialPardonForm1);
		bureaucrat.executeForm(presidentialPardonForm1);
		bureaucrat.executeForm(presidentialPardonForm1);
		bureaucrat.executeForm(presidentialPardonForm1);
		
		std::cout << "------------------------------" << std::endl << std::endl;
		std::cout << "presidential pardon form test for " << presidentialPardonForm2.getName();
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		bureaucrat.executeForm(presidentialPardonForm2);
		bureaucrat.signForm(presidentialPardonForm2);
		bureaucrat.executeForm(presidentialPardonForm2);
		bureaucrat.executeForm(presidentialPardonForm2);
		std::cout << "------------------------------" << std::endl << std::endl;
	}
	std::cout << "\033[33m----------------------------------\033[0m" << std::endl << std::endl;
	return (0);
}
