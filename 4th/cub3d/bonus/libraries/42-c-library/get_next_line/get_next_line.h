/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:25:01 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/14 20:42:34 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_gnl_strchr(const char *s, int c);
void	*ft_gnl_calloc(size_t num, size_t size);
void	ft_gnl_bzero(void *s, size_t n);
size_t	count_except_nl(char *buffer);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);

#endif