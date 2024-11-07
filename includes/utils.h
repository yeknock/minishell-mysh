#ifndef UTILS_H
# define UTILS_H

size_t  ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
int		ft_isalpha(int c);
int	    ft_is_special(int c);

#endif