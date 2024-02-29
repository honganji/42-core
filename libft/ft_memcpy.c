#include "libft.h"

void	*ft_memcpy(void *dest, void *src, int n)
{
	char	*ptr_dest;
	char	*ptr_src;

	ptr_dest = dest;
	ptr_src = src;
	while (n--)
	{
		*ptr_dest++ = *ptr_src++;
	}
	*ptr_dest = '\0';
	return (dest);
}
