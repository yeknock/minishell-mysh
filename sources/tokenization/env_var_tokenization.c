#include "../../includes/minishell.h"


void	env_var_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token	*new_node;
	char	*variable_name;
	int		j;
	int		first_index;
	int		last_index;

	j = *index;
	first_index = 0;
	last_index = 0;
	while(str[j])
	{
		if (str[j] == '$' && (str[j+1] == '_' || ft_isalpha(str[j+1]) || ft_isdigit(str[j+1])))
			first_index = j + 1;

		if ((str[j] == '_' || ft_isalpha(str[j]) || ft_isdigit(str[j])) && \
			(str[j+1] != '_' && !ft_isalpha(str[j+1]) && !ft_isdigit(str[j+1])))
		{
			last_index = j;
			break;
		}
		j++;
	}
	variable_name = ft_substr(str, first_index, last_index - first_index + 1);
	if (variable_name && *variable_name != '\0' && first_index != 0)
	{
		new_node = create_t_node(ENV_VAR, variable_name);
		add_t_node_to_back(tokens_list, new_node);
	}
	*index += last_index - first_index + 1;
}