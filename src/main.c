#include "../headers/minishell.h"

int main(int argc, char **argv, char **envp)
{
	rl_bind_key('\t', rl_complete);
	char	*input;

	while(1)
	{
		printf("\x1B[31m");
		input = readline("\e[1mmysh$\x1B[0m\e[m ");

		// The EOF part
		if (!input)
		{
			clear_history(); // this should be changed to rl_clear_history()
			break;
		}
		// This part should be using for parsing and execution
		printf("%s\n", input);
		// rl_on_new_line();
		
		// Add commands to history list
		if (input && *input)
			add_history(input);
		free(input);
	}
	return 0;
}