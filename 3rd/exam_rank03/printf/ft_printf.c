/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:49 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/23 15:19:30 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_arg(va_list ap, t_state *state, char c)
{
	if (c == 'c')
		ft_put_chr(state, va_arg(ap, int));
	else if (c == 's')
		ft_put_str(state, va_arg(ap, char *));
	else if (c == 'p')
	{
		ft_put_str(state, "0x");
		if (!state->has_error)
			return ;
		ft_put_address(state, va_arg(ap, unsigned long));
	}
	else if (c == 'X' || c == 'x')
		ft_put_num(state, va_arg(ap, unsigned int), c);
	else if (c == 'd' || c == 'i')
		ft_put_num(state, va_arg(ap, int), c);
	else if (c == 'u')
		ft_put_num(state, va_arg(ap, unsigned int), c);
	else if (c == '%')
		ft_put_chr(state, '%');
}

static void	ft_put(va_list ap, t_state *state, char **str)
{
	if (**str == '%')
	{
		(*str)++;
		ft_put_arg(ap, state, **str);
	}
	else
		ft_put_chr(state, **str);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	t_state	*state;
	char	*args;

	count = 0;
	state = (t_state *)malloc(1 * sizeof(t_state));
	if (!state)
		return (-1);
	*state = (t_state){0, 1};
	va_start(ap, str);
	args = (char *)str;
	while (*args)
	{
		ft_put(ap, state, &args);
		if (!state->has_error)
		{
			free(state);
			va_end(ap);
			return (-1);
		}
		args++;
	}
	count = state->count;
	free(state);
	va_end(ap);
	return (count);
}
