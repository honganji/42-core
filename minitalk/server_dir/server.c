/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:59:41 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/10 19:48:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_data	g_data;

static void	print_chr(int sig)
{
	char	c;

	if (sig == SIGUSR1)
		c = 1;
	else
		c = 0;
	g_data.tmp = g_data.tmp | (c << g_data.i--);
	if (g_data.i == -1)
	{
		g_data.i = 7;
		write(1, &(g_data.tmp), 1);
		g_data.tmp = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	g_data.tmp = 0;
	g_data.i = 7;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, print_chr);
	signal(SIGUSR2, print_chr);
	while (1)
		pause();
	return (0);
}
