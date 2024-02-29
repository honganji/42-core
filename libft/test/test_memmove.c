#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_memmove(void)
{
	char	memmove_src[30] = "I want to be a dentist!";
	char	ft_memmove_src[30] = "I want to be a dentist!";
	int		size;
	int		is_correct;

	size = 30;
	memmove(memmove_src + 15, memmove_src, 8);
	ft_memmove(ft_memmove_src + 15, ft_memmove_src, 8);
	for (size_t i = 0; i < size; i++)
	{
		is_correct *= memmove_src[i] == ft_memmove_src[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
