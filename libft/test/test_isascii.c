#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_isascii(void)
{
	char	*char_arr;
	int		is_correct;

	char_arr = "aH2l /:@^34";
	for (size_t i = 0; i < strlen(char_arr); i++)
	{
		is_correct *= isascii(char_arr[i]) == ft_isascii(char_arr[i]);
	}
	return (is_correct ? "Yes!" : "No...");
}
