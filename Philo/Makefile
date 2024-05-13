CC			= cc

NAME		= pipex

SRC			= $(addprefix ./philo/, main.c init.c get_cmd.c open_file.c		\
			  clean_exit.c exec_cmd.c)

OBJ			:= $(SRC:.c=.o)

CFLAGS		= -Wextra -Wall -Werror -g -pthread

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
