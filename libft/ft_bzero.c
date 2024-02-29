#include "libft.h"

void	ft_bzero(void *s, int n)
{
	char	*p;

	p = s;
	while (n--)
	{
		*p++ = 0;
	}
}
