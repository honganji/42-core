#include "libft.h"

static int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *s)
{
	int		length;
	char	*value;
	int		count;

	length = get_strlen(s);
	value = (char *)malloc((length + 1) * sizeof(char));
	count = 0;
	while (s[count])
	{
		value[count] = s[count];
		count++;
	}
	value[count] = '\0';
	return (value);
}
