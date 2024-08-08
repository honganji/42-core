#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

bool test(std::string formName, std::string targetName)
{
	std::cout << formName << std::endl;
	Intern intern;
	Bureaucrat bureaucrat(44);
	AForm *form;
	try
	{
		form = intern.makeForm(formName, targetName);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	bureaucrat.executeForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
	return (true);
}

int main(void)
{
	// Test for making Robotom Request Form
	{
		std::cout << "\033[31mTest for making Robotom Request Form\033[0m" << std::endl;
		std::cout << "\033[31m----------------------------------\033[0m" << std::endl;
		if (!test("robotomy request", "Levi"))
			return (1);
	}
	std::cout << "\033[31m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for making Shrubbery Creation Form
	{
		std::cout << "\033[32mTest for making Shrubbery Creation Form\033[0m" << std::endl;
		std::cout << "\033[32m----------------------------------\033[0m" << std::endl;
		if (!test("shrubbery creation", "Mikasa"))
			return (1);
	}
	std::cout << "\033[32m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for making Presidential Pardon Form
	{
		std::cout << "\033[33mTest for making Presidential Pardon Form\033[0m" << std::endl;
		std::cout << "\033[33m----------------------------------\033[0m" << std::endl;
		if (!test("presidential pardon", "Almin"))
			return (1);
	}
	std::cout << "\033[33m----------------------------------\033[0m" << std::endl << std::endl;
	
	// Test for making Fake form
	{
		std::cout << "\033[34mTest for making Fake form\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------\033[0m" << std::endl;
		if (!test("fake request", "Albert"))
		{
			std::cout << "\033[34m----------------------------------\033[0m" << std::endl << std::endl;
			return (1);
		}		
	}
	return (0);
}
