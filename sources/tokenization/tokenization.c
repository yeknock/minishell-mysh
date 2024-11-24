#include "../../includes/minishell.h"



void	word_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	unsigned int	first_index;
	unsigned int	last_index;
	int				j;

	j = *index;
	first_index = 0;
	last_index = 0;
	while(str[j])
	{
		if ((j == *index && !ft_is_special(str[j])) || \
			(j > 0 && ft_is_special(str[j - 1]) && !ft_is_special(str[j])))
			first_index = j;
		if (ft_is_special(str[j+1]))
		{
			last_index = j;
			break;
		}
		j++;
	}
	seperated_str = ft_substr(str, first_index, last_index - first_index + 1);
	if (seperated_str && *seperated_str != '\0')
	{
		new_node = create_t_node(WORD, seperated_str);
		add_t_node_to_back(tokens_list, new_node);
	}
	*index += last_index - first_index + 1;
}





void	pipe_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	int				j;
	int				count_of_pipes;

	j = *index;
	count_of_pipes = 0;
	seperated_str = "|";
	while(str[j])
	{
		if (str[j] != '|')
			break;
		new_node = create_t_node(PIPE, seperated_str);
		add_t_node_to_back(tokens_list, new_node);
		if (str[j] == '|' && str[j+1] != '|')
			break;
		else
			count_of_pipes++;
		j++;
	}
	*index += count_of_pipes;
}



t_token	*tokenization(char *rd_line)
{
	t_token	*tokens_list;
	int		index;

	tokens_list = NULL;
	index = 0;
	while(rd_line[index] != '\0')
	{
		if (!ft_is_special(rd_line[index]))
			word_tokenization(rd_line, &tokens_list, &index);
		if (rd_line[index] == '|')
			pipe_tokenization(rd_line, &tokens_list, &index);
		if (rd_line[index] == '"')
			db_quotes_tokenization(rd_line, &tokens_list, &index);
		if (rd_line[index] == '\'')
			sg_quotes_tokenization(rd_line, &tokens_list, &index);
		if (rd_line[index] == '<')
			redin_hdoc_tokenization(rd_line, &tokens_list, &index);
		if (rd_line[index] == '>')
			redout_append_tokenization(rd_line, &tokens_list, &index);
		if (rd_line[index] == '$')
			env_var_tokenization(rd_line, &tokens_list, &index);
		index++;
	}
	return (tokens_list);
}