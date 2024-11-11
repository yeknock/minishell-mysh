# Project name
NAME = minishell

# Readline name
READLINE = readline

# Compilator
CC = cc

# Compilator flags
INC_DIRS = -I./includes -I./$(LIBS_DIR)/$(READLINE)/include
CFLAGS =  $(INC_DIRS) -Wall -Wextra -Werror

# Libraries
LIBS_DIR = libraries
READLINE_LIB_PATH = $(LIBS_DIR)/readline/lib

# Headers
HEADERS = 	includes/minishell.h \
			includes/utils.h \
			includes/tokenization.h

# Source directory
SRCS_DIR = sources/

# Objects directory
OBJS_DIR = objects/

# Source file names
SRCS_NAME = main.c \
			utils/ft_strlen.c \
			utils/ft_substr.c \
			utils/ft_split.c \
			utils/ft_isalpha.c \
			utils/ft_is_special.c \
			tokenization/tokenization.c \
			tokenization/create_t_node.c \
			tokenization/add_token_to_back.c \
			tokenization/print_tokens_list.c \
			tokenization/redin_redout_tokenization.c \
			tokenization/db_quotes_tokenization.c \

# Objects file names
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

# Compilation process
all: $(LIBS_DIR)/$(READLINE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -l$(READLINE) -L$(READLINE_LIB_PATH)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/utils
	@mkdir -p $(OBJS_DIR)/tokenization
	$(CC) $(CFLAGS) -c $< -o $@

# Configuring readline
$(LIBS_DIR)/$(READLINE): 
	./$(LIBS_DIR)/config_readline readline

# Cleaning
clean:
	@$(RM) $(OBJS)

# Force cleaning
fclean: clean
	@$(RM) $(NAME)
	rm -rf $(LIBS_DIR)/$(READLINE)
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBS_DIR)/readline-8.2

# Remaking
re: fclean all

# PHONY files
.PHONY: all clean fclean re