#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strnstr(void)
{
	char	str_1[40] = "Take it easy";
	char	str_2[40] = "it";
	char	*str_strnstr;
	char	*str_ft_strnstr;
	int		size;
	int		is_correct;

	size = 9;
	str_strnstr = strnstr(str_1, str_2, size);
	str_ft_strnstr = ft_strnstr(str_1, str_2, size);
	if (str_strnstr == NULL)
		return (str_strnstr == str_ft_strnstr ? "Yes!" : "No...");
	for (size_t i = 0; i < strlen(str_strnstr); i++)
	{
		is_correct *= str_strnstr[i] == str_ft_strnstr[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
