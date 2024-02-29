#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_memset(void)
{
	char	mem_memset[20] = "abcd";
	char	ft_mem_memset[20] = "abcd";
	int		is_correct;

	memset(mem_memset, 'a', sizeof(mem_memset) - 1);
	ft_memset(ft_mem_memset, 'a', sizeof(ft_mem_memset) - 1);
	for (size_t i = 0; i < sizeof(mem_memset); i++)
	{
		is_correct *= mem_memset[i] == ft_mem_memset[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
