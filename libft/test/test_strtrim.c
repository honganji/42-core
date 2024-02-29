#include "../libft.h"
#include <stdio.h>

struct		test
{
	char	s1[30];
	char	set[30];
};

void	test_strtrim(void)
{
	int	count;

	struct test test_case[] = {
		{"I don't like it", "like"},
		{"aaaaa bbbbbb cccc ddddd", "d"},
		{"I want to have a party", "to"},
		{"water", ""},
	};
	count = 0;
	while (count < (int)(sizeof(test_case) / sizeof(struct test)))
	{
		printf("case %d\n", count);
		printf("string: %s, set: %s\n", test_case[count].s1,
			test_case[count].set);
		printf("result: %s\n", ft_strtrim(test_case[count].s1,
				test_case[count].set));
		count++;
	}
	printf("\n");
}
