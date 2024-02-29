#include "libft.h"

static int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_strlcat(char *dest, char *src, int size)
{
	int	count;
	int	dest_size;
	int	src_size;

	count = 0;
	src_size = get_strlen(src);
	dest_size = get_strlen(dest);
	while (dest[count])
		count++;
	if (dest_size < size)
	{
		while (count < size - 1)
		{
			dest[count] = src[count - dest_size];
			count++;
		}
		dest[count] = '\0';
	}
	if (dest_size >= size)
		return (src_size + size);
	else
		return (dest_size + src_size);
	return (0);
}
