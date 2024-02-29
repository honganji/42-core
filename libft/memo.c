// char	**ft_split_v1(char const *s, char c)
// {
// 	char	**str_arr;
// 	int		count;
// 	int		size;
// 	int		word_len;

// 	size = count_word(s, c);
// 	str_arr = (char **)malloc((size + 1) * sizeof(char *));
// 	count = 0;
// 	if (!*s || !str_arr)
// 		return (NULL);
// 	while (*s)
// 	{
// 		word_len = get_len_split(s, c);
// 		*str_arr = (char *)malloc((word_len + 1) * sizeof(char));
// 		if (!*str_arr)
// 			return (NULL);
// 		while (*s != ',')
// 			*((*str_arr)++) = *s++;
// 		**str_arr = '\0';
// 		*str_arr++ -= word_len;
// 		s++;
// 	}
// 	*str_arr = NULL;
// 	str_arr -= size;
// 	return (str_arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str_arr;
// 	int		arr_count;
// 	int		str_count;
// 	int		element_count;

// 	str_arr = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
// 	arr_count = 0;
// 	str_count = 0;
// 	element_count = 0;
// 	if (!s[str_count] || !str_arr)
// 		return (NULL);
// 	while (s[str_count])
// 	{
// 		str_arr[arr_count] = (char *)malloc((get_len_split(&s[str_count], c)
// 					+ 1) * sizeof(char));
// 		if (!str_arr[arr_count])
// 			return (NULL);
// 		while (s[str_count] != c)
// 			str_arr[arr_count][element_count++] = s[str_count++];
// 		str_arr[arr_count++][element_count] = '\0';
// 		element_count = 0;
// 		str_count++;
// 	}
// 	str_arr[arr_count] = NULL;
// 	// printf("first element: %s\n", str_arr[0]);
// 	return (str_arr);
// }
