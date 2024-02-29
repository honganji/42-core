#include "test.h"
#include <stdio.h>

int	main(void)
{
	printf("Start testing...\n\n");
	printf("Part1:\n");
	printf("-------------------------\n");
	printf("ft_atoi: %s\n", test_atoi());
	printf("ft_bzero: %s\n", test_bzero());
	printf("ft_calloc: %s\n", test_calloc());
	printf("ft_isalnum: %s\n", test_isalnum());
	printf("ft_isalpha: %s\n", test_isalpha());
	printf("ft_isascii: %s\n", test_isascii());
	printf("ft_isdigit: %s\n", test_isdigit());
	printf("ft_isprint: %s\n", test_isprint());
	printf("ft_memchr: %s\n", test_memchr());
	printf("ft_memcmp: %s\n", test_memcmp());
	printf("ft_memcpy: %s\n", test_memcpy());
	printf("ft_memmove: %s\n", test_memmove());
	printf("ft_memset: %s\n", test_memset());
	printf("ft_memset: %s\n", test_memset());
	printf("ft_strchr: %s\n", test_strchr());
	printf("ft_strdup: %s\n", test_strdup());
	printf("ft_strlcat: %s\n", test_strlcat());
	printf("ft_strlcpy: %s\n", test_strlcpy());
	printf("ft_strlen: %s\n", test_strlen());
	printf("ft_strcmp: %s\n", test_strncmp());
	printf("ft_strnstr: %s\n", test_strnstr());
	printf("ft_strrchr: %s\n", test_strrchr());
	printf("ft_toupper: %s\n", test_toupper());
	printf("ft_tolower: %s\n", test_tolower());
	printf("-------------------------\n");
	printf("Part2:\n");
	printf("-------------------------\n");
	printf("ft_substr:\n");
	test_substr();
	printf("ft_strjoin:\n");
	test_strjoin();
	printf("ft_strtrim:\n");
	test_strtrim();
	printf("ft_itoa:\n");
	test_itoa();
	printf("ft_split:\n");
	test_split();
	printf("-------------------------\n");
	printf("End testing...\n");
	return (0);
}
