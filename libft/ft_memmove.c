#include "libft.h"

void	*ft_memmove(void *dest, void *src, int n)
{
	char	*ptr_dest;
	char	*ptr_src;

	ptr_dest = dest;
	ptr_src = src;
	if (dest >= src)
	{
		while (n--)
		{
			*ptr_dest++ = *ptr_src++;
		}
	}
	else
	{
		ptr_dest += n - 1;
		ptr_src += n - 1;
		while (dest < src)
		{
			*ptr_dest-- = *ptr_src--;
		}
	}
	return (dest);
}
