#ifndef PARSING_H
# define PARSING_H


typedef enum e_parse_state
{
	EXPECT_COMMAND,
	EXPECT_ARGUMENT,
	EXPECT_FILE,
	ERROR_STATE
} t_parse_state;


typedef struct s_command {
    char	*command;        // The command name
    char	**arguments;     // Array of arguments
    char	*redir_in;       // Input redirection file
    char	*redir_out;      // Output redirection file
    int		append_out;       // Flag for append mode (>>)
    struct	s_command *next;  // For pipes, link to next command
} t_command;






#endif