#include "../includes/minishell.h"

static	int	matrix_elements_counter(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	if (s[ft_strlen(s) - 1] == c)
		j--;
	return (j);
}

static	void	matrix_free(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static	void	modified_matrix(char **matrix, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		len = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
				len++;
			}
			matrix[j] = ft_substr((s + i) - len, 0, len);
			if (matrix[j] == NULL)
				matrix_free(matrix);
			j++;
		}
		else
			i++;
	}
	matrix[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	if (*s == '\0')
	{
		ret = (char **)malloc(sizeof(char *));
		ret[0] = NULL;
		return (ret);
	}
	ret = (char **)malloc(sizeof(char *) * (matrix_elements_counter(s, c) + 1));
	if (!ret)
		return (0);
	modified_matrix(ret, s, c);
	return (ret);
}