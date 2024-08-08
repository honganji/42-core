/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuji <yuji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:53:07 by yuji              #+#    #+#             */
/*   Updated: 2024/05/26 16:59:52 by yuji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "../philo.h"

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

void	setup_philo(t_data *data);
void	setup_monitor(t_data *data);

#endif