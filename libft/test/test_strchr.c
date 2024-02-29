#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strchr(void)
{
	char	c;
	char	str[20] = "I want ice cream";
	char	*str_strchr;
	char	*str_ft_strchr;
	int		is_correct;

	c = 'c';
	str_strchr = strchr(str, c);
	str_ft_strchr = ft_strchr(str, c);
	for (size_t i = 0; i < strlen(str_strchr); i++)
	{
		is_correct *= str_strchr[i] == str_ft_strchr[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
