/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:27:28 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:56 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char	*str;

	c = '9';
	str = NULL;
	ft_printf("make this %c, your name is %s age is %d temprature is %i, \
		the address of c is %p, hex num %x, HEX NUM %X\n", 'c', "Yuji", 10, \
		-30, &c, 123123123131, 123131123123);
	printf("make this %c, your name is %s age is %d temprature is %i, \
		the address of c is %p, hex num %lx, HEX NUM %lX\n", 'c', "Yuji", \
		10, -30, &c, 123123123131, 123131123123);
	return (0);
}
