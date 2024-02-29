int	ft_atoi(char *str)
{
	int	sign;
	int	ab_num;

	sign = 1;
	ab_num = 0;
	while (*str <= ' ' && *str != '\0')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ab_num = 10 * ab_num + (*str - '0');
		str++;
	}
	return (ab_num * sign);
}
