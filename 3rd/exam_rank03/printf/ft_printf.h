/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:38:22 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/23 15:06:50 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_state
{
	int	count;
	int	has_error;
}t_state;

int		ft_printf(const char *str, ...);
void	ft_put_chr(t_state *state, char c);
void	ft_put_str(t_state *state, char *str);
void	ft_put_num(t_state *state, long num, char c);
void	ft_put_address(t_state *state, unsigned long num);

#endif