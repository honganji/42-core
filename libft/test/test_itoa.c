#include "../libft.h"
#include <stdio.h>

struct	test
{
	int	num;
};

void	test_itoa(void)
{
	int count;

	struct test test_case[] = {
		2432423,
		5234,
		2346,
		22344,
		-3,
		0,
		-2147483648,
		2147483647,
	};
	count = 0;
	while (count < (int)(sizeof(test_case) / sizeof(struct test)))
	{
		printf("case %d\n", count);
		printf("number: %d\n", test_case[count].num);
		printf("result: %s\n", ft_itoa(test_case[count].num));
		count++;
	}
	printf("\n");
}
