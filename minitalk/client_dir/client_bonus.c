/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:41:43 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/10 19:56:19 by ytoshihi         ###   ########.fr       */
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

static void	send_num(int num, pid_t pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if ((num >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

static void	send_string(char *str, pid_t pid, int own_pid)
{
	send_num(ft_strlen(str), pid);
	send_num(own_pid, pid);
	while (*str)
		send_char_bit((unsigned char)(*str++), pid);
}

static void	confirm(int sig)
{
	sig++;
	ft_putstr_fd("I got the reply", 1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	own_pid;

	signal(SIGUSR2, confirm);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		own_pid = getpid();
		send_string(argv[2], pid, own_pid);
	}
	return (0);
}
