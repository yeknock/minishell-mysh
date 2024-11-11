#include "../../includes/minishell.h"

void	db_quotes_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	int				j;
	int				count_of_db_quotes;

	j = *index;
	count_of_db_quotes = 0;
	seperated_str = "\"";
	while(str[j])
	{
		if (str[j] != '"')
			break;
		if (str[j+1] && (str[j] == '"' && str[j+1] != '"'))
		{
			new_node = create_t_node(DOUBLE_QUOTES, seperated_str);
			add_t_node_to_back(tokens_list, new_node);
			break;
		}
		else
		{
			new_node = create_t_node(DOUBLE_QUOTES, seperated_str);
			add_t_node_to_back(tokens_list, new_node);
			count_of_db_quotes++;
		}
		j++;
	}
	*index += count_of_db_quotes;
}