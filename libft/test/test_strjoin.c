#include "../libft.h"
#include <stdio.h>

struct		test
{
	char	str1[30];
	char	str2[30];
};

void	test_strjoin(void)
{
	int	count;

	struct test test_case[] = {
		{"I wanna ", "see you"},
		{"bump of ", "chicken"},
		{"", "king"},
		{"water", ""},
	};
	count = 0;
	while (count < (int)(sizeof(test_case) / sizeof(struct test)))
	{
		printf("case %d\n", count);
		printf("first_string: %s, second_string: %s\n", test_case[count].str1,
			test_case[count].str2);
		printf("result: %s\n", ft_strjoin(test_case[count].str1,
				test_case[count].str2));
		count++;
	}
	printf("\n");
}
