#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strncmp(void)
{
	char	str_1[20] = "HELLe";
	char	str_2[20] = "HELLo";
	int		is_correct;

	is_correct = strncmp(str_1, str_2, 5) == ft_strncmp(str_1, str_2, 5);
	return (is_correct ? "Yes!" : "No...");
}
