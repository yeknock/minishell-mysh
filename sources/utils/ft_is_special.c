#include "../includes/minishell.h"

int	ft_is_special(int c)
{
	if (c == '|' || c == '$' || c == '<' || c == '>' || c == ' ' || c == '\0')
		return (1);
	return (0);
}