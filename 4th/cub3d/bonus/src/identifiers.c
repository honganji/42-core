/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:25:13 by mkijewsk          #+#    #+#             */
/*   Updated: 2024/07/26 16:44:44 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	comma_incoming(char *s)
{
	while (s && *s == ' ')
		s++;
	if (*s == ',')
		return (1);
	else
		return (0);
}

void	remove_spaces(char *s)
{
	char	*res;
	int		flag;

	res = s;
	flag = 0;
	while (s && *s)
	{
		if (ft_isdigit(*s))
			flag = 0;
		if (comma_incoming(s))
			flag = 1;
		if (flag && *s == ' ')
			++s;
		else
			*res++ = *s++;
	}
	*res = '\0';
}
