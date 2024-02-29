#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_atoi(void)
{
	char	*str_arr[] = {"  f  \n+434sdfs", "-94358", "989", "   +09-sidfh"};
	int		is_correct;

	for (size_t i = 0; i < sizeof(str_arr) / sizeof(char *); i++)
	{
		is_correct *= atoi(str_arr[i]) == ft_atoi(str_arr[i]);
	}
	return (is_correct ? "Yes!" : "No...");
}
