#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	rl_bind_key('\t', rl_complete);
	char	*input;
	
	(void)argc;
	(void)argv;
	(void)envp;
	while(1)
	{
		printf("\x1B[31m");
		input = readline("\e[1mmysh$\x1B[0m\e[m ");
		if (!input)
			exit(0);	//this part of code handles to Ctrl+D (exiting program part)

		t_token *a = tokenization(input);
		print_tokens_list(&a);
		free(a);
		
		if (input && *input)
			add_history(input);
		free(input);
	}
	system("leaks ./minishell");
	return 0;
}
