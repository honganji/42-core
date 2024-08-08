/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:34:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:29 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (count);
		while (*s != c && *s)
			s++;
		count++;
	}
	return (count);
}

static char	*word_dup(int start, int end, const char *str)
{
	char	*word;
	int		size;

	size = end - start;
	word = (char *)malloc((size + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (size--)
		word[end - start - size - 1] = str[start + (end - start - size - 1)];
	word[end - start] = '\0';
	return (word);
}

static char	**free_arr(char **str_arr)
{
	int	count;

	count = 0;
	while (str_arr[count])
		free(str_arr[count++]);
	free(str_arr[count]);
	free(str_arr);
	return (NULL);
}

static void	check_chr(char const *s, int *end, char c)
{
	while (s[*end] == c)
		(*end)++;
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		start;
	int		end;
	int		index;

	str_arr = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	start = 0;
	end = 0;
	index = 0;
	if (!s || !str_arr)
		return (NULL);
	while (s[end])
	{
		check_chr(s, &end, c);
		start = end;
		if (!s[end])
			break ;
		while (s[end] != c && s[end])
			end++;
		str_arr[index] = word_dup(start, end, s);
		if (!str_arr[index++])
			return (free_arr(str_arr));
	}
	str_arr[index] = NULL;
	return (str_arr);
}
