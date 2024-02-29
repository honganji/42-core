#include "../libft.h"
#include <stdio.h>

struct			test
{
	char const	*s;
	char		c;
};

static int	count_word(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	if (!*s)
		return (count);
	while (*s)
	{
		if (flag)
		{
			count++;
			flag = 0;
		}
		if (*s == c)
			flag = 1;
		s++;
	}
	return (count);
}

void	test_split(void)
{
	char	**str_arr;

	struct test test_case[] = {
		{"king,pig,give,house", ','},
		{"king,pig,give,house", ','},
		{"king,pig,give,house", ','},
		{"king,pig,give,house", ','},
		{"I like the player", ' '},
		{"k|u|s|o|y|a|r|o", '|'},
		{"", '|'},
		{"lemon", '|'},
	};
	for (size_t i = 0; i < sizeof(test_case) / sizeof(struct test); i++)
	{
		printf("case %zu\n", i);
		printf("string: %s, character: %c\n", test_case[i].s, test_case[i].c);
		str_arr = ft_split(test_case[i].s, test_case[i].c);
		for (size_t j = 0; j < count_word(test_case[i].s, test_case[i].c); j++)
		{
			printf("str%zu: %s\n", j, str_arr[j]);
		}
	}
	printf("\n");
}
