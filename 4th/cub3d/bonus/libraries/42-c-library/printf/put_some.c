/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_some.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:31:44 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/14 20:12:17 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_chr(char c, t_state *state)
{
	state->has_error = write(1, &c, 1) + 1;
	state->count++;
	if (!state->has_error)
		return ;
}

void	put_str(char *str, t_state *state)
{
	if (!str)
	{
		put_str("(null)", state);
		return ;
	}
	while (*str)
	{
		put_chr(*str++, state);
		if (!state->has_error)
			return ;
	}
}

void	put_hex_nbr(unsigned long address, t_state *state, int is_lower)
{
	char	*base;

	if (is_lower)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (address / 16 > 0)
	{
		put_hex_nbr(address / 16, state, is_lower);
		if (!state->has_error)
			return ;
	}
	put_chr(base[address % 16], state);
	if (!state->has_error)
		return ;
}

void	put_signed_num(int num, t_state *state)
{
	if (num == -2147483648)
	{
		put_str("-2147483648", state);
		return ;
	}
	if (num < 0)
	{
		put_chr('-', state);
		if (!state->has_error)
			return ;
		num *= -1;
	}
	if (num / 10 > 0)
	{
		put_signed_num(num / 10, state);
		if (!state->has_error)
			return ;
	}
	put_chr(num % 10 + '0', state);
}

void	put_unsigned_num(unsigned int num, t_state *state)
{
	if (num / 10 > 0)
	{
		put_signed_num(num / 10, state);
		if (!state->has_error)
			return ;
	}
	put_chr(num % 10 + '0', state);
}
