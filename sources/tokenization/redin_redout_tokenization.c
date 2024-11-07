#include "../../includes/minishell.h"

void	redin_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	unsigned int	j;
	int				count_of_redirs;

	j = 0;
	count_of_redirs = 0;
	seperated_str = "<";
	while(str[j])
	{
		if (str[j] != '<')
			break;
		else
		{
			new_node = create_t_node(REDIR_IN, seperated_str);
			add_t_node_to_back(tokens_list, new_node);
			count_of_redirs++;
		}
		j++;
	}
	*index += count_of_redirs;
}





void	redout_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	unsigned int	j;
	int				count_of_redouts;

	j = 0;
	count_of_redouts = 0;
	seperated_str = ">";
	while(str[j])
	{
		if (str[j] != '>')
			break;
		else
		{
			new_node = create_t_node(REDIR_IN, seperated_str);
			add_t_node_to_back(tokens_list, new_node);
			count_of_redouts++;
		}
		j++;
	}
	*index += count_of_redouts;
}