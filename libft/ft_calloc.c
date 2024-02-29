#include "libft.h"

void	*ft_calloc(int num, int size)
{
	void *p;

	p = malloc(num * size);
	return (p);
}
