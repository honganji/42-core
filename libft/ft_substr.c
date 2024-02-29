#include <stdlib.h>

static int	get_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		count;

	str = (char *)malloc((len + 1) * sizeof(char));
	count = 0;
	if (get_strlen(s) - start < len || !str)
		return (NULL);
	while (count < (int)len)
	{
		str[count] = s[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
