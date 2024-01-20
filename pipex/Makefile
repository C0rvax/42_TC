CC			= cc

NAME		= pipex

vpath %.c src/ gnl/

SRC			= main.c init.c get_cmd.c open_file.c clean_exit.c exec_cmd.c

GNL_SRC		= get_next_line.c get_next_line_utils.c

OBJ			:= $(SRC:%.c=%.o)

CFLAGS		= -Wextra -Wall -Werror

HEADERS		= -I./Include

LIBRARIES	= -L./printf -lftprintf -L./libft -lft

all			: $(NAME)

$(NAME)		: $(OBJ) $(GNL_OBJ)
		make -C printf
		make -C libft
		$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

%.o			: %.c
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean		:
		rm -f $(OBJ) $(GNL_OBJ)
		make clean -C printf
		make clean -C libft

fclean		: clean
		rm -f $(NAME)
		make fclean -C printf
		make fclean -C libft

re			: fclean all

.PHONY		: all clean fclean re
