#include "include/Span.hpp"

int main()
{
	// Test for normal input
	{
		std::cout << "\033[32mTest for normal input\033[0m" << std::endl;
		std::cout << "\033[32m---------------------------\033[0m" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\033[32m---------------------------\033[0m" << std::endl << std::endl;

	// Test for insane input
	{
		std::cout << "\033[31mTest for insane input\033[0m" << std::endl;
		std::cout << "\033[31m---------------------------\033[0m" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\033[31m---------------------------\033[0m" << std::endl << std::endl;

	// Test for trying to add exceeded number of elemets
	{
		std::cout << "\033[33mTest for trying to add exceeded number of elemets\033[0m" << std::endl;
		std::cout << "\033[33m---------------------------\033[0m" << std::endl;
		Span sp = Span(5);
		for (size_t i = 0; i < 6; i++)
		{
			try
			{
				sp.addNumber(i);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\033[33m---------------------------\033[0m" << std::endl << std::endl;

	// Test for too less elements
	{
		std::cout << "\033[34mTest for too less elements\033[0m" << std::endl;
		std::cout << "\033[34m---------------------------\033[0m" << std::endl;
		Span sp = Span(1);
		sp.addNumber(0);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "\033[34m---------------------------\033[0m" << std::endl << std::endl;
	return 0;
}
