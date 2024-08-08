#include "../include/Span.hpp"

std::vector<int> *Span::getVec(void) const
{
	return (_vec);
}

unsigned int Span::getIndex(void) const
{
	return (_index);
}

void Span::addNumber(const int num)
{
	if (getIndex() >= getVec()->size())
		throw(TooManyElements());
	getVec()->at(_index++) = num;
}

Span::Span(unsigned int N)
{
	_vec = new std::vector<int>(N);
	_index = 0;
	for (size_t i = 0; i < N; i++)
		_vec->at(i) = 0;
	std::cout << "Span instance is created!" << std::endl;
}

Span::Span(const Span &ref)
{
	std::vector<int> *refVec = ref.getVec();
	_vec = new std::vector<int>(refVec->size());
	for (size_t i = 0; i < _vec->size(); i++)
		_vec->at(i) = refVec->at(i);
}

Span &Span::operator=(const Span &ref)
{
	_index = ref.getIndex();
	if (this != &ref)
	{	
		std::vector<int> *refVec = ref.getVec();
		for (size_t i = 0; i < _vec->size(); i++)
				_vec->at(i) = refVec->at(i);
	}
	return (*this);
}

Span::~Span(void)
{
	delete _vec;
	std::cout << "Span instance is destroyed!" << std::endl;	
}

unsigned int Span::shortestSpan(void) const
{
	std::vector<int> *sortVec(&(*getVec()));
	unsigned int minSpan = UINT_MAX;
	unsigned int span;

	if (sortVec->size() < 2)
		throw(NotEnoughElements());
	std::sort(sortVec->begin(), sortVec->end());
	for (size_t i = 0; i < sortVec->size() - 1; i++)
	{
		span = static_cast<unsigned int>(sortVec->at(i + 1) - sortVec->at(i));
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

unsigned int Span::longestSpan(void) const
{
	std::vector<int> *sortVec(&(*getVec()));

	if (sortVec->size() < 2)
		throw(NotEnoughElements());
	std::sort(sortVec->begin(), sortVec->end());
	return (sortVec->at(sortVec->size() - 1) - sortVec->at(0));
}
