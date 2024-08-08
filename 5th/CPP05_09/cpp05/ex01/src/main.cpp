#include "../include/Bureaucrat.hpp"

int main(void)
{
	// Test for default constructor, getter function, and sign function
	{
		std::cout << "\033[31mTest for default constructor, getter function, and sign function\033[0m" << std::endl;
		std::cout << "\033[31m----------------------------------\033[0m" << std::endl;
		Form *form = NULL;
		Bureaucrat *bureaucrat = NULL;
		try
		{
			form = new Form();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bureaucrat = new Bureaucrat(1);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete form;
		}
		// Test operator '<<'
		std::cout << *form;
		std::cout << "the form name is " << form->getName() << std::endl;
		std::cout << "the form sign grade is " << form->getGradeSign() << std::endl;
		std::cout << "the form exe grade is " << form->getGradeExe() << std::endl;
		std::cout << "the form is " << (form->getIsSigned() ? "singed" : "not signed") << std::endl;
		bureaucrat->signForm(*form);
		std::cout << "the form is " << (form->getIsSigned() ? "singed" : "not signed") << std::endl;
		delete form;
		delete bureaucrat;
	}
	std::cout << "\033[31m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for too low sign grade
	{
		std::cout << "\033[32mTest for too low sign grade\033[0m" << std::endl;
		std::cout << "\033[32m----------------------------------\033[0m" << std::endl;
		try
		{
			Form("Form", 151, 20);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[32m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for too low exe grade
	{
		std::cout << "\033[33mTest for too low exe grade\033[0m" << std::endl;
		std::cout << "\033[33m----------------------------------\033[0m" << std::endl;
		try
		{
			Form("Form", 20, 200);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[33m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for too high sign grade
	{
		std::cout << "\033[34mTest for too high sign grade\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------\033[0m" << std::endl;
		try
		{
			Form("Form", -151, 20);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[34m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for too high exe grade
	{
		std::cout << "\033[36mTest for too high exe grade\033[0m" << std::endl;
		std::cout << "\033[36m----------------------------------\033[0m" << std::endl;
		try
		{
			Form("Form", 15, -20);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[36m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for failing sign a form
	{
		std::cout << "\033[35mTest for failing sign a form\033[0m" << std::endl;
		std::cout << "\033[35m----------------------------------\033[0m" << std::endl;
		Form *form = NULL;
		Bureaucrat *bureaucrat = NULL;
		try
		{
			form = new Form();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bureaucrat = new Bureaucrat(100);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete form;
		}
		std::cout << "the form is " << (form->getIsSigned() ? "singed" : "not signed") << std::endl;
		bureaucrat->signForm(*form);
		std::cout << "the form is " << (form->getIsSigned() ? "singed" : "not signed") << std::endl;
		delete form;
		delete bureaucrat;
	}
	std::cout << "\033[35m----------------------------------\033[0m" << std::endl << std::endl;
	return (0);
}
