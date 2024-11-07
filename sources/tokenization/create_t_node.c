#include "../../includes/minishell.h"

t_token *create_t_node(t_token_type type, char *value)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (0);
	new_node -> type = type;
	new_node -> value = value;
	new_node -> next = NULL;
	return (new_node);
}