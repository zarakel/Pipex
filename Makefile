CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = child_process.c utilities.c copies.c pipex.c malloc.c \
parent_process.c main.c problems.c fill_string_cmd.c \

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: pipex all clean fclean re
