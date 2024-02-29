#include "../libft.h"
#include <stdio.h>

struct		test
{
	char	str[30];
	int		start;
	int		len;
};

void	test_substr(void)
{
	int	count;

	struct test test_case[] = {
		{"I make a cake!", 2, 5},
		{"King of throne", 5, 5},
		{"", 1, 5},
		{"May I help you?", 8, 15},
	};
	count = 0;
	while (count < (int)(sizeof(test_case) / sizeof(struct test)))
	{
		printf("case %d\n", count);
		printf("base_string: %s, start_index: %d, length: %d\n",
			test_case[count].str, test_case[count].start, test_case[count].len);
		printf("result: %s\n", ft_substr(test_case[count].str,
				test_case[count].start, test_case[count].len));
		count++;
	}
	printf("\n");
}
