/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:59:41 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/10 19:49:23 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_data		g_data;

static void	get_num(int sig)
{
	int	num;

	num = 1;
	if (sig == SIGUSR1)
		num = 1;
	else
		num = 0;
	if (!g_data.is_len)
		g_data.len = g_data.len | (num << g_data.i--);
	else
		g_data.pid = g_data.pid | (num << g_data.i--);
	if (g_data.i == -1)
	{
		if (!g_data.is_len)
		{
			g_data.i = 31;
			g_data.is_len = 1;
		}
		else
		{
			g_data.i = 7;
			g_data.is_len = 2;
		}
	}
}

static void	reset_data(void)
{
	g_data.tmp = 0;
	g_data.i = 31;
	g_data.len = 0;
	g_data.is_len = 0;
	g_data.pid = 0;
}

static void	print_chr(int sig)
{
	char	c;

	if (g_data.is_len < 2)
		get_num(sig);
	else
	{
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
			g_data.len--;
		}
		if (!g_data.len)
		{
			kill(g_data.pid, SIGUSR2);
			reset_data();
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	g_data.tmp = 0;
	g_data.i = 31;
	g_data.len = 0;
	g_data.is_len = 0;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, print_chr);
	signal(SIGUSR2, print_chr);
	while (1)
		pause();
	return (0);
}
