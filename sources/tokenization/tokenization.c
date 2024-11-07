#include "../../includes/minishell.h"


void	iteration_on_white_spaces(char *str, int *index)
{
	unsigned int	j;

	j = 0;
	while(str[j] != '\0')
	{
		if (str[j] != ' ')
			break;
		j++;
	}
	*index += j;
}



void	word_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	unsigned int	first_index;
	unsigned int	last_index;
	unsigned int	j;

	j = 0;
	first_index = 0;
	last_index = 0;
	while(str[j])
	{
		if (ft_is_special(str[j]))
			break;
		if(j > 0 && !ft_is_special(str[j]) && ft_is_special(str[j-1]))
			first_index = j; // here we keep the first index of a word token
		if (str[j+1] && !ft_is_special(str[j]) && ft_is_special(str[j+1]))
			last_index = j; // here we keep the last index of a word token
		j++;
	}
	seperated_str = ft_substr(str, first_index, last_index - first_index + 1);
	if (seperated_str && *seperated_str != '\0')
	{
		new_node = create_t_node(WORD, seperated_str);
		add_t_node_to_back(tokens_list, new_node);
	}
	if (last_index - first_index == 0)
		*index += 0;
	else
		*index += last_index - first_index;
}




void	pipe_tokenization(char *str, t_token **tokens_list, int *index)
{
	t_token			*new_node;
	char			*seperated_str;
	unsigned int	j;
	int				count_of_pipes;

	j = 0;
	count_of_pipes = 0;
	seperated_str = "|";
	while(str[j])
	{
		if (str[j] != '|')
			break;
		else
		{
			new_node = create_t_node(PIPE, seperated_str);
			add_t_node_to_back(tokens_list, new_node);
			count_of_pipes++;
		}
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
		word_tokenization(rd_line + index, &tokens_list, &index);
		printf("%d----word\n", index);
		pipe_tokenization(rd_line + index, &tokens_list, &index);
		printf("%d----pipe\n", index);
		iteration_on_white_spaces(rd_line + index, &index);
		printf("%d----spaces\n", index);
		index++;
	}
	return (tokens_list);
}