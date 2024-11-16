#include "../../includes/minishell.h"

void	print_tokens_list(t_token **lst)
{
	t_token	*temp;

	temp = *lst;
	while(temp)
	{
		printf("%s \e[1m->\x1B[0m\e[m ", temp -> value);
		temp = temp -> next;
	}
	printf("\n");
}