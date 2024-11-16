#include "../../includes/minishell.h"

void	redin_hdoc_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token		*new_node;
	int			j;
	int			count_of_redin_hdoc;

	j = *index;
	count_of_redin_hdoc = 0;
	while(str[j])
	{
		if (str[j] == '<' && str[j+1] == '<')
		{
			new_node = create_t_node(REDIR_HEREDOC, "<<");
			add_t_node_to_back(tokens_list, new_node);
			j++;
			count_of_redin_hdoc += 2;
		}
		else if (str[j] == '<' && str[j+1] != '<')
		{
			new_node = create_t_node(REDIR_IN, "<");
			add_t_node_to_back(tokens_list, new_node);
			count_of_redin_hdoc++;
			break;
		}
		j++;
	}
	*index += count_of_redin_hdoc;
}




void	redout_append_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token		*new_node;
	int			j;
	int			count_of_redout_append;

	j = *index;
	count_of_redout_append = 0;
	while(str[j])
	{
		if (str[j] == '>' && str[j+1] == '>')
		{
			new_node = create_t_node(REDIR_HEREDOC, ">>");
			add_t_node_to_back(tokens_list, new_node);
			j++;
			count_of_redout_append += 2;
		}
		else if (str[j] == '>' && str[j+1] != '>')
		{
			new_node = create_t_node(REDIR_IN, ">");
			add_t_node_to_back(tokens_list, new_node);
			count_of_redout_append++;
			break;
		}
		j++;
	}
	*index += count_of_redout_append;
}
