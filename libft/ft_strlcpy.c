#include "libft.h"

static int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	count;

	count = get_strlen(src);
	while (size-- > 1 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (count);
}
