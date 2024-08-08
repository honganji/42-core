/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:57:05 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/24 10:33:34 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	char	*new_line;
	int		line_count;
	int		read_count;

	line_count = 0;
	read_count = 0;
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!(new_line = ft_strchr(line, '\n'))
		&& (read_count = read(fd, buffer, BUFFER_SIZE)))
	{
		if (read_count < 0)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		buffer[read_count] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	if (!ft_strlen(line))
	{
		buffer[0] = '\0';
		return (free(line), NULL);
	}
	if (new_line)
	{
		line_count = new_line - line + 1;
		ft_strcpy(buffer, new_line + 1);
	}
	else
	{
		line_count = ft_strlen(line);
		buffer[0] = '\0';
	}
	ft_substr(line, line_count);
	return (line);
}
