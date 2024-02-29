#include <stdlib.h>

static int	get_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	check_if_same(char *str1, char const *set)
{
	while (*set)
	{
		if (*str1++ != *set++)
			return (0);
	}
	return (1);
}

static void	trim_str(char *s1, char const *set, int *s1_size)
{
	char	*tmp;

	tmp = s1;
	while (*set++)
	{
		*s1_size = *s1_size - 1;
		tmp++;
	}
	while (*tmp)
		*s1++ = *tmp++;
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*str;
	char	*start_ptr;
	int		s1_size;
	int		count;

	start_ptr = s1;
	s1_size = get_strlen(s1);
	count = 0;
	while (*s1)
	{
		if (check_if_same(s1, set))
			trim_str(s1, set, &s1_size);
		s1++;
	}
	start_ptr[s1_size] = '\0';
	str = (char *)malloc((get_strlen(start_ptr) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*start_ptr)
	{
		str[count++] = *start_ptr++;
	}
	str[count] = '\0';
	return (str);
}
