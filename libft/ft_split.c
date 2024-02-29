#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	get_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	count_word(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	if (!*s)
		return (count);
	while (*s)
	{
		if (flag)
		{
			count++;
			flag = 0;
		}
		if (*s == c)
			flag = 1;
		s++;
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
	{
		word[end - start - size - 1] = str[start + (end - start - size - 1)];
	}
	word[end + (end - start - size)] = '\0';
	return (word);
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
	if (!s[end] || !str_arr)
		return (NULL);
	while (s[end])
	{
		if (s[end] == c)
		{
			str_arr[index++] = word_dup(start, end++, s);
			start = end;
		}
		else
		{
			end++;
		}
	}
	str_arr[index++] = word_dup(start, end, s);
	str_arr[index] = NULL;
	return (str_arr);
}
