#include "libft.h"

static int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	check_if_same(char *str1, char *str2, int size)
{
	while (size--)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	needle_size;

	needle_size = get_strlen(needle);
	while (*haystack && len--)
	{
		if (check_if_same(haystack, needle, needle_size))
			return (haystack);
		haystack++;
	}
	return (NULL);
}
