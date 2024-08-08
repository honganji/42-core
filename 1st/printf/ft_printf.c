/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:01 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/21 14:40:56 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_each_function(const char **str, va_list	ap, t_state	**state)
{
	if (**str == '%')
	{
		(*str)++;
		put_with_condition((char)**str, ap, *state);
	}
	else
		put_chr(**str, *state);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_state	*state;
	int		count;

	va_start(ap, str);
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (-1);
	state->count = 0;
	state->has_error = 1;
	while (*str)
	{
		print_each_function(&str, ap, &state);
		if (!state->has_error)
		{
			free(state);
			va_end(ap);
			return (-1);
		}
		str++;
	}
	count = state->count;
	free(state);
	va_end(ap);
	return (count);
}
