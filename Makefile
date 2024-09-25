CC = cc
FLAGS = -Wall -Wextra -Werror -lreadline
SOURCES = 		src/
					main.c
OBJECTS = 
NAME = minishell
READLINE_INCLUDE = $(shell brew --prefix readline)/include
READLINE_LIB = $(shell brew --prefix readline)/lib
INCLUDES = -I./includes -I./lib/libft -I$(READLINE_INCLUDE)

all:

$(NAME):


clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: 

.PHONY: all $(NAME) fclean clean re