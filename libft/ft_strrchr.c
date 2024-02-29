#include "libft.h"

static int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strrchr(char *str, int c)
{
	int	count;

	count = get_strlen(str) - 1;
	if (*str == '\0')
		return (NULL);
	while (count != 0)
	{
		if (str[count] == c)
			return (&str[count]);
		count--;
	}
	return (NULL);
}
