#include "stdio.h"
#include "string.h"
#include "test.h"

char	*test_strrchr(void)
{
	char	str[40] = "Take it easy";
	char	c;
	char	*str_strrchr;
	char	*str_ft_strrchr;
	int		size;
	int		is_correct;

	c = 'i';
	str_strrchr = strrchr(str, c);
	str_ft_strrchr = ft_strrchr(str, c);
	if (str_strrchr == NULL)
		return (str_strrchr == str_ft_strrchr ? "Yes!" : "No...");
	for (size_t i = 0; i < strlen(str_strrchr); i++)
	{
		is_correct *= str_strrchr[i] == str_ft_strrchr[i];
	}
	return (is_correct ? "Yes!" : "No...");
}
