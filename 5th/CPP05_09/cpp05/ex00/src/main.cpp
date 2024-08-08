#include "../include/Bureaucrat.hpp"

int main(void)
{
	// Test for default constructor
	{
		std::cout << "\033[31mTest for default constructor\033[0m" << std::endl;
		std::cout << "\033[31m----------------------------------\033[0m" << std::endl;
		Bureaucrat *bureaucrat1 = NULL;
		try
		{
			bureaucrat1 = new Bureaucrat();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		// Test operator <<
		std::cout << *bureaucrat1;
		std::cout << "the bureaucrat1 name is " << bureaucrat1->getName() << std::endl;
		std::cout << "the bureaucrat1 grade is " << bureaucrat1->getGrade() << std::endl;
		try
		{
			bureaucrat1->increment();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "the bureaucrat1 grade after incrementing is " << bureaucrat1->getGrade() << std::endl;
		try
		{
			bureaucrat1->decrement();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "the bureaucrat1 grade after decrementing is " << bureaucrat1->getGrade() << std::endl;
		delete bureaucrat1;
	}
	std::cout << "\033[31m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for valid input
	{
		std::cout << "\033[32mTest for valid input\033[0m" << std::endl;
		std::cout << "\033[32m----------------------------------\033[0m" << std::endl << std::endl;
		Bureaucrat *bureaucrat2 = NULL;
		try
		{
			bureaucrat2 = new Bureaucrat(100);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "the bureaucrat2 name is " << bureaucrat2->getName() << std::endl;
		std::cout << "the bureaucrat2 grade is " << bureaucrat2->getGrade() << std::endl;
		delete bureaucrat2;
	}
	std::cout << "\033[32m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for too high input
	{
		std::cout << "\033[33mTest for too high input\033[0m" << std::endl;
		std::cout << "\033[33m----------------------------------\033[0m" << std::endl;
		Bureaucrat *bureaucrat3 = NULL;
		try
		{
			bureaucrat3 = new Bureaucrat(-3);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete bureaucrat3;
		}
	}
	std::cout << "\033[33m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for too low input
	{
		std::cout << "\033[34mTest for too low input\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------\033[0m" << std::endl;
		Bureaucrat *bureaucrat4 = NULL;
		try
		{
			bureaucrat4 = new Bureaucrat(200);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete bureaucrat4;
		}
		delete bureaucrat4;
	}
	std::cout << "\033[34m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for increment error
	{
		std::cout << "\033[35mTest for increment error\033[0m" << std::endl;
		std::cout << "\033[35m----------------------------------\033[0m" << std::endl;
		Bureaucrat *bureaucrat4 = NULL;
		try
		{
			bureaucrat4 = new Bureaucrat(2);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete bureaucrat4;
		}
		try
		{
			bureaucrat4->increment();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete bureaucrat4;
		}
		try
		{
			bureaucrat4->increment();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bureaucrat4->increment();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat4;
	}
	std::cout << "\033[35m----------------------------------\033[0m" << std::endl << std::endl;

	// Test for decrement error
	{
		std::cout << "\033[36mTest for decrement error\033[0m" << std::endl;
		std::cout << "\033[36m----------------------------------\033[0m" << std::endl;
		Bureaucrat *bureaucrat5 = NULL;
		try
		{
			bureaucrat5 = new Bureaucrat(149);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			delete bureaucrat5;
		}
		try
		{
			bureaucrat5->decrement();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bureaucrat5->decrement();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bureaucrat5->decrement();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat5;
	}
	std::cout << "\033[36m----------------------------------\033[0m" << std::endl;
	return (0);
}
