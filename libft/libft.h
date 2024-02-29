#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *s);
void	*ft_memset(void *s, int c, int n);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dest, void *src, int n);
void	*ft_memmove(void *dest, void *src, int n);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlcat(char *dest, char *src, int size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, int n);
void	*ft_memchr(void *s, int c, int n);
int		ft_memcmp(void *s1, void *s2, int n);
char	*ft_strnstr(char *haystack, char *needle, int len);
int		ft_atoi(char *str);
char	*ft_strdup(char *s);
void	*ft_calloc(int num, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
