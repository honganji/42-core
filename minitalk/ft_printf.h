/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/17 18:37:06 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./mand/mand.h"
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);

#endif