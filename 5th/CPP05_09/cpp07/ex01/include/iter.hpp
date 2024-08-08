#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T>
void iter(T *a, size_t len, void (*fun)(T &))
{
	for (size_t i = 0; i < len; i++)
		fun(a[i]);
}

#endif
