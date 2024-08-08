#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _len;

	public:
		Array(void);
		Array(unsigned int len);
		Array(const Array &ref);
		Array &operator=(const Array &ref);
		T &operator[](int i);
		T *getArray(void) const;
		unsigned int size(void) const;
		~Array(void);
		class OutOfRange : public std::exception
		{
			const char *what() const throw()
			{
				return ("Out of range!");
			}
		};
};

template <typename T>
Array<T>::Array(void)
{
	_array = nullptr;
	_len = 0;
	std::cout << "Empty Array is created!" << std::endl;
};

template <typename T>
Array<T>::Array(unsigned int len)
{
	_array = new T[len];
	_len = len;
	std::cout << "The Array is created sized: " << _len << std::endl;
}

template <typename T>
Array<T>::~Array(void)
{
	delete _array;
	std::cout << "The Array is destroyed" << std::endl;
};

template <typename T>
T *Array<T>::getArray(void) const
{
	return (_array);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_len);
}

template <typename T>
T &Array<T>::operator[](int i)
{
	if (i >= (int)size() || i < 0)
		throw (OutOfRange());
	return (getArray()[i]);
}

template <typename T>
Array<T>::Array(const Array &ref)
{
	_len = ref.size();
	_array = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		_array[i] = ref.getArray()[i];
	std::cout << "The Array is deep copied by assigning" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &ref)
{
	if (this != *ref)
	{
		for (int i = 0; i < _len; i++)
			_array[i] = ref.getArray()[i];
	}
	std::cout << "The Array is deep copied with equal sign" << std::endl;
	return (*this);
}

#endif
