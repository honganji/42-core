#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

#include "../include/Span.hpp"

class Span
{
	private:
		std::vector<int> *_vec;
		unsigned int _index;

	  public:
		Span(unsigned int N);
		Span(const Span &ref);
		Span &operator=(const Span &ref);
		~Span(void);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		void addNumber(const int num);
		std::vector<int> *getVec(void) const;
		unsigned int getIndex(void) const;
		class TooManyElements : public std::exception
		{
			public:
			const char *what() const throw()
			{
				return ("Too many elements");
			}
		};
		class NotEnoughElements : public std::exception
		{
			public:
			const char *what() const throw()
			{
				return ("Not enough elements!");
			}
		};
};

#endif
