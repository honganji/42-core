#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_isprint(void)
{
	char	*char_arr;
	int		is_correct;

	char_arr = "aH2l /:@^34";
	for (size_t i = 0; i < strlen(char_arr); i++)
	{
		is_correct *= isprint(char_arr[i]) == ft_isprint(char_arr[i]);
	}
	return (is_correct ? "Yes!" : "No...");
}
