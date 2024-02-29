#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_bzero(void)
{
	char	zero_arr[20];
	char	ft_zero_arr[20];
	int		is_correct;

	bzero(zero_arr, sizeof(zero_arr) - 1);
	ft_bzero(ft_zero_arr, sizeof(ft_zero_arr) - 1);
	for (size_t i = 0; i < sizeof(zero_arr) / sizeof(char) - 1; i++)
	{
		is_correct *= zero_arr[i] == ft_zero_arr[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
