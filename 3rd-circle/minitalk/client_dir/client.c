/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:41:43 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/10 17:30:01 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

static void	send_char_bit(unsigned char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

static void	send_string(char *str, pid_t pid)
{
	while (*str)
		send_char_bit((unsigned char)(*str++), pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid ;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_string(argv[2], pid);
	}
	return (0);
}
