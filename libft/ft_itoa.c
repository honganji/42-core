#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		count;
	int		tmp;
	char	*value;

	count = 0;
	tmp = n;
	value = "make";
	if (n == -2147483648)
		return ("-2147483648");
	while (tmp)
	{
		tmp /= 10;
		count++;
	}
	if (n < 0)
		count++;
	value = (char *)malloc(count * sizeof(char));
	if (!value)
		return (NULL);
	if (n < 0)
	{
		value[0] = '-';
		n *= -1;
	}
	count--;
	while (n)
	{
		value[count--] = n % 10 + '0';
		n /= 10;
	}
	return (value);
}
