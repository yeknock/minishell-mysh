#ifndef TOKENIZATION_H
# define TOKENIZATION_H

typedef enum e_token_type
{
	WORD,			// For commands and arguments
	PIPE,			// For '|'
	REDIR_IN,		// For '<'
	REDIR_OUT,		// For '>'
	REDIR_APPEND,	// For '>>'
	REDIR_HEREDOC,	// For '<<'
	DOUBLE_QUOTES,	// For ""
	SINGLE_QUOTES,	// For ''
	ENV_VAR,		// For environment variables
}   t_token_type;


typedef struct s_token
{
	t_token_type type;
	char        *value;
	struct s_token *next;
}   t_token;



t_token		*create_t_node(t_token_type type, char *value);
void		add_t_node_to_back(t_token **t_lst, t_token *new);
void		print_tokens_list(t_token **lst);
t_token		*tokenization(char *rd_line);
void		word_tokenization(char *str, t_token **tokens_list, int *index);
void		pipe_tokenization(char *str, t_token **tokens_list, int *index);
void		redin_tokenization(char *str, t_token **tokens_list, int *index);
void		redout_tokenization(char *str, t_token **tokens_list, int *index);
void		iteration_on_white_spaces(char *str, int *index);

#endif