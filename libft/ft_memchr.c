#include "libft.h"

void	*ft_memchr(void *s, int c, int n)
{
	char	*p;

	p = (char *)s;
	while (*p && n--)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}
