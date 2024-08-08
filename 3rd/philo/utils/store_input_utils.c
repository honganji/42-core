/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:22:53 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/02 11:58:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Move each input argument one by one
 * 
 * @param argc the number of argument
 * @param argv the array of arguments
 * 
 * @return void
*/
void	modify_argv(int argc, char ***argv)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		(*argv)[i] = (*argv)[i + 1];
}
