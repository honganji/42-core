/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:27:58 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/23 13:19:46 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join(char *buffer, char *tmp)
{
	char	*str;

	str = ft_strjoin(buffer, tmp);
	free(buffer);
	return (str);
}

char	*ft_read(int fd, char *buffer)
{
	int		result;
	char	tmp[BUFFER_SIZE + 1];

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	result = 1;
	while (result)
	{
		result = read(fd, tmp, BUFFER_SIZE);
		if (result < 0)
			return (free(buffer), NULL);
		tmp[result] = '\0';
		buffer = ft_join(buffer, tmp);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		count;
	char	*str;
	char	*tmp;

	count = 0;
	tmp = buffer;
	if (!*buffer)
		return (NULL);
	while (*buffer && *buffer != '\n')
	{
		buffer++;
		count++;
	}
	if (*buffer == '\n')
		count++;
	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (*tmp && *tmp != '\n')
		str[count++] = *tmp++;
	if (*tmp == '\n')
		str[count++] = '\n';
	str[count] = '\0';
	return (str);
}

char	*update_buffer(char *buffer)
{
	char	*str;
	int		count_str;
	char	*tmp;

	tmp = buffer;
	count_str = 0;
	while (*tmp && *tmp != '\n')
		tmp++;
	if (!*tmp)
		return (free(buffer), NULL);
	str = ft_calloc(ft_strlen(tmp) + 1, sizeof(char));
	if (!str)
		return (free(buffer), NULL);
	tmp++;
	while (*tmp)
	{
		str[count_str++] = *tmp;
		tmp++;
	}
	str[count_str] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
