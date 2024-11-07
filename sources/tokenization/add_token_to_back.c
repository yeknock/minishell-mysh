#include "../../includes/minishell.h"

void    add_t_node_to_back(t_token **t_lst, t_token *new)
{
	t_token	*temp;

	if (!new)
		return ;
	if (*t_lst == NULL)
		*t_lst = new;
	else
	{
		temp = *t_lst;
		while(temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
}