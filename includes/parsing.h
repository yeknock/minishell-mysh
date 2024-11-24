#ifndef PARSING_H
# define PARSING_H


typedef enum e_parser_state
{
    EXPECT_COMMAND,       // Expecting a command (after a pipe, or at the beginning).
    EXPECT_ARGUMENT,      // Expecting arguments (after a command or redirection).
    EXPECT_PIPE,          // Expecting a pipe symbol.
    EXPECT_REDIRECT_IN,   // Expecting an input redirection ("<").
    EXPECT_REDIRECT_OUT,  // Expecting an output redirection (">").
    EXPECT_REDIRECT_APPEND, // Expecting a redirection with append (">>").
    EXPECT_HEREDOC,       		// Expecting a heredoc ("<<").
    ERROR_STATE           		// Syntax error state.
}   t_parser_state;


typedef struct s_parser_state {
    t_token_type current_type;   // Type of the current token (e.g., COMMAND, ARGUMENT)
    t_token *current_token;      // Pointer to the current token being processed
    int index;                   // Current position in the input string (or token list)
    t_token **tokens_list;       // List of tokens to be parsed
} t_parser_state;


typedef struct s_command {
    char	*command;        // The command name
    char	**arguments;     // Array of arguments
    char	*redir_in;       // Input redirection file
    char	*redir_out;      // Output redirection file
    int		append_out;       // Flag for append mode (>>)
    struct	s_command *next;  // For pipes, link to next command
} t_command;






#endif