#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strlcpy(void)
{
	char	str_src[20] = "I want ice cream";
	char	str_strcpy_dest[20];
	char	str_ft_strcpy_dest[20];
	int		size;
	int		is_correct;

	size = 5;
	strlcpy(str_strcpy_dest, str_src, size);
	ft_strlcpy(str_ft_strcpy_dest, str_src, size);
	for (size_t i = 0; i < strlen(str_strcpy_dest); i++)
	{
		is_correct *= str_strcpy_dest[i] == str_ft_strcpy_dest[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
