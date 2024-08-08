/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:53:59 by yuji              #+#    #+#             */
/*   Updated: 2024/06/02 12:13:15 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

int		store_input(int argc, char **argv, int args[5]);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		ft_isnum(char *str);
void	initialize(t_data *data, int *args);
size_t	ft_get_current_time(void);
void	ft_usleep(size_t usec);
size_t	stamp(t_data *data);
int		get_diff(t_data *data, int i);
void	set_last_time(t_data *data, int i);
int		check_num(int args[5]);
void	clean_data(t_data *data);
void	modify_argv(int argc, char ***argv);
void	error(void);
void	free_str_arr(char **arr);

#endif