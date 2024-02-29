#include <stdlib.h>

static int	get_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int count;

	str = (char *)malloc((get_strlen(s1) + get_strlen(s2) + 1) * sizeof(char));
	count = 0;
	if (!str)
		return (NULL);
	while (*s1)
		str[count++] = *s1++;
	while (*s2)
		str[count++] = *s2++;
	str[count] = '\0';
	return (str);
}
