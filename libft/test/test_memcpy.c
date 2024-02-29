#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_memcpy(void)
{
	char	memcpy_dest[20];
	char	ft_memcpy_dest[20];
	char	src[20] = "Lebron";
	int		size;
	int		is_correct;

	size = 6;
	memcpy(memcpy_dest, src, 6);
	ft_memcpy(ft_memcpy_dest, src, 6);
	for (int i = 0; i < size; i++)
	{
		is_correct *= memcpy_dest[i] == ft_memcpy_dest[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
