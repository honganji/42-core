/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_some.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/23 15:19:54 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_chr(t_state *state, char c)
{
	state->has_error = write(1, &c, 1) + 1;
	state->count++;
}

void	ft_put_str(t_state *state, char *str)
{
	if (str == NULL)
	{
		ft_put_str(state, "(null)");
		return ;
	}
	while (*str)
	{
		ft_put_chr(state, *str);
		if (!state->has_error)
			return ;
		str++;
	}
}

void	ft_put_num(t_state *state, long num, char c)
{
	char	*base_str;
	int		base_num;

	base_num = 10;
	if (c == 'i' || c == 'd' || c == 'u')
	{
		base_str = "0123456789";
		base_num = 10;
		if (num == -2147483648)
		{
			ft_put_str(state, "-2147483648");
			return ;
		}
		if (num < 0)
		{
			ft_put_chr(state, '-');
			if (!state->has_error)
				return ;
			num = -num;
		}
	}
	if (c == 'p' | c == 'x' | c == 'X')
	{
		if (c == 'X')
			base_str = "0123456789ABCDEF";
		else
			base_str = "0123456789abcdef";
		base_num = 16;
	}
	if (num / base_num)
	{
		ft_put_num(state, num / base_num, c);
		if (!state->has_error)
			return ;
	}
	ft_put_chr(state, base_str[num % base_num]);
}

void	ft_put_address(t_state *state, unsigned long num)
{
	char	*base_str;
	int		base_num;

	base_str = "0123456789abcdef";
	base_num = 16;
	if (num / base_num)
	{
		ft_put_address(state, num / base_num);
		if (!state->has_error)
			return ;
	}
	ft_put_chr(state, base_str[num % base_num]);
}
