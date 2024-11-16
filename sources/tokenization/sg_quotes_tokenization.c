#include "../../includes/minishell.h"

void	sg_quotes_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token		*new_node;
	int			j;
	int			first_index;
	int			last_index;
	char		*inner_word;

	j = *index;
	inner_word = NULL;
	new_node = NULL;
	first_index = 0;
	last_index = 0;
	while(str[j])
	{
		if (str[j] == '\'' && str[j+1] == '\'')
		{
			new_node = create_t_node(SINGLE_QUOTES, "'");
			add_t_node_to_back(tokens_list, new_node);
			new_node = create_t_node(SINGLE_QUOTES, "'");
			add_t_node_to_back(tokens_list, new_node);
			*index += 1;
			return ;
		}
		if (str[j] == '\'' && str[j+1] != '\'')
			first_index = j + 1;
		if (str[j] != '\'' && str[j+1] == '\'')
		{
			last_index = j;
			new_node = create_t_node(SINGLE_QUOTES, "'");
			add_t_node_to_back(tokens_list, new_node);
			break;
		}
		j++;
	}
	if (str[j] == '\0')
	{
		printf("\nError!\n");
		return ;
	}
	inner_word = ft_substr(str, first_index, last_index - first_index + 1);
	if (inner_word && *inner_word != '\0')
	{
		new_node = create_t_node(WORD, inner_word);
		add_t_node_to_back(tokens_list, new_node);
		new_node = create_t_node(SINGLE_QUOTES, "'");
		add_t_node_to_back(tokens_list, new_node);
	}
	*index += last_index - first_index + 2;
}