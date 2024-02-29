#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_memcmp(void)
{
	char	str_1[20] = "Hello";
	char	str_2[20] = "Hellw";
	int		size;
	int		is_correct;

	size = 5;
	for (int i = 0; i < size; i++)
	{
		is_correct *= memcmp(str_1, str_2, i) == ft_memcmp(str_1, str_2, i);
	}
	return (is_correct ? "Yes!" : "No...");
}
