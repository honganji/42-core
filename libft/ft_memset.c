#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	char	*p;

	p = s;
	while (n--)
	{
		*p++ = (char)c;
	}
	*p = '\0';
	return (s);
}
