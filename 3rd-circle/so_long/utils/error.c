/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:52:04 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:13 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error(char *err_mes)
{
	// system("leaks so_long");
	ft_printf("Error\n%s", err_mes);
	exit(EXIT_FAILURE);
}
