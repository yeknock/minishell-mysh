#include "../../includes/minishell.h"

void	print_tokens_list(t_token **lst)
{
	t_token	*temp;

	temp = *lst;
	while(temp)
	{
		printf("%s -> ", temp -> value);
		temp = temp -> next;
	}
	printf("\n");
}