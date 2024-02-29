#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_calloc(void)
{
	char	*mem_calloc;
	char	*ft_mem_calloc;
	int		size;
	int		is_correct;

	size = 10;
	mem_calloc = calloc(size, sizeof(char));
	ft_mem_calloc = ft_calloc(size, sizeof(char));
	for (size_t i = 0; i < size; i++)
	{
		is_correct *= mem_calloc[i] == ft_mem_calloc[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
