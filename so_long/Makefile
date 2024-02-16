NAME		= so_long

vpath %.c src/ gnl/

SRC			= main.c init.c display.c check_wall.c move.c init_map.c		\
			  utils.c end_game.c utils2.c

GNL_SRC		= get_next_line.c get_next_line_utils.c

OBJ			:= $(SRC:%.c=%.o)

GNL_OBJ		:= $(GNL_SRC:%.c=%.o)

CC 			= cc

CFLAGS		= -Wextra -Wall -Werror

HEADERS		= -Imlx -I./include

LIBRARIES	= -Lmlx -lmlx -L./printf -lftprintf -L./libft -lft \
			  -lXext -lX11 -lm -lz

all			: $(NAME)

$(NAME)		: $(OBJ) $(GNL_OBJ)
	make -C mlx
	make -C printf
	make -C libft
	$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

%.o			: %.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

clean		:
	rm -f $(OBJ) $(GNL_OBJ)
	make clean -C mlx
	make clean -C printf
	make clean -C libft

fclean		: clean
	rm -f $(NAME)
	make clean -C mlx
	make fclean -C printf
	make fclean -C libft
	
re			: fclean all

.PHONY		: all clean fclean re
