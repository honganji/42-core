#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strlcat(void)
{
	char	c;
	char	str_strlcat_dest[20] = "I want";
	char	str_ft_strlcat_dest[20] = "I want";
	char	str_src[20] = "ice cream";
	int		is_correct;

	c = 'c';
	strlcat(str_strlcat_dest, str_src, 9);
	ft_strlcat(str_ft_strlcat_dest, str_src, 9);
	for (size_t i = 0; i < strlen(str_strlcat_dest); i++)
	{
		is_correct *= str_strlcat_dest[i] == str_ft_strlcat_dest[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
