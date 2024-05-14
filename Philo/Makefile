CC			= cc

NAME		= philo

SRC			= $(addprefix ./philo/, main.c init.c exit_error.c utils.c		\

OBJ			:= $(SRC:.c=.o)

CFLAGS		= -Wextra -Wall -Werror -g

HEADERS		= -I./include

all			: $(NAME)

$(NAME)		: $(OBJ)
		$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

%.o			: %.c
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean		:
		rm -f $(OBJ)

fclean		: clean
		rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
