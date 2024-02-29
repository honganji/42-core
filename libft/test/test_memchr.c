#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_memchr(void)
{
	char	*memchr_value;
	char	*ft_memchr_value;
	char	str_memchr[30] = "He gave me such a great life";
	char	c_memchr;
	int		is_correct;

	c_memchr = 'g';
	memchr_value = (char *)memchr(str_memchr, c_memchr, 20);
	ft_memchr_value = (char *)ft_memchr(str_memchr, c_memchr, 20);
	for (size_t i = 0; i < strlen(memchr_value); i++)
	{
		is_correct *= memchr_value[i] == ft_memchr_value[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
