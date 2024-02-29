#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_toupper(void)
{
	char	*char_arr;
	int		is_correct;

	char_arr = "aH2l /:@^34";
	is_correct = 1;
	for (size_t i = 0; i < strlen(char_arr); i++)
	{
		is_correct *= (toupper(char_arr[i]) == ft_toupper(char_arr[i]));
	}
	return (is_correct ? "Yes!" : "No...");
}
