/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_with_condition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:20:05 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/14 20:12:22 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_with_condition(char c, va_list ap, t_state *state)
{
	if (c == 'c')
		put_chr(va_arg(ap, int), state);
	else if (c == 's')
		put_str(va_arg(ap, char *), state);
	else if (c == 'p')
	{
		put_str("0x", state);
		if (!state->has_error)
			return ;
		put_hex_nbr(va_arg(ap, unsigned long), state, 1);
	}
	else if (c == 'x')
		put_hex_nbr(va_arg(ap, unsigned int), state, 1);
	else if (c == 'X')
		put_hex_nbr(va_arg(ap, unsigned int), state, 0);
	else if (c == 'd' || c == 'i')
		put_signed_num(va_arg(ap, int), state);
	else if (c == 'u')
		put_unsigned_num(va_arg(ap, unsigned int), state);
	else if (c == '%')
		put_chr(c, state);
	else
		state->has_error = 0;
}
