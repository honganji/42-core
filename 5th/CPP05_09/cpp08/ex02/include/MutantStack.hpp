#ifndef MUTAN_STACK_HPP
# define MUTAN_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	  MutantStack(void);
	  MutantStack(const MutantStack &ref);
	  MutantStack &operator=(const MutantStack &ref);
	  ~MutantStack(void);
	  typedef typename std::stack<T>::container_type::iterator iterator;
	  iterator begin(void)
	  {
		  return (this->c.begin());
	  }
	  iterator end(void)
	  {
		  return (this->c.end());
	  }
};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	std::cout << "MutantStack instance is created!" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ref) : std::stack<T>(ref)
{
	*this = ref;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &ref)
{
	std::stack<T>::operator=(ref);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack instance is destroyed!" << std::endl;	
}

#endif
