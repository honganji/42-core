/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:42:19 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/10 18:49:58 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <signal.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct data
{
	char	tmp;
	int		i;
	int		len;
	int		is_len;
	int		pid;
}t_data;

typedef struct new_data
{
	char	str[100];
	int		chr_count;
	int		str_count;
	int		len;
	char	tmp;
	int		is_len;
}t_new_data;

#endif
