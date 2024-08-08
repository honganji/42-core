/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:38:14 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/02 11:56:52 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Print Error message
 * 
 * @return void
*/
void	error(void)
{
	char	*str;

	str = "The arguments should be numbers and each argument represent those\n"
		"1. number_of_philosophers\n"
		"2. time_to_die\n"
		"3. time_to_eat\n"
		"4. time_to_sleep\n"
		"5. number_of_times_each_philosopher_must_eat (optional argument)\n";
	write(2, str, 205);
}
