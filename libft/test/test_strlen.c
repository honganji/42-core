#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strlen(void)
{
	char	str[20] = "I want ice cream";
	int		is_correct;

	is_correct = strlen(str) == ft_strlen(str);
	return (is_correct ? "Yes!" : "No...");
}
