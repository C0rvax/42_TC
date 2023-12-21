NAME		= so_long

vpath %.c src/ gnl/

SRC			= main.c initiate.c main_loop.c display.c		\
			  display_back.c check_exit.c move.c test_path.c

GNL_SRC		= get_next_line.c get_next_line_utils.c

OBJ			:= $(SRC:%.c=%.o)

GNL_OBJ		:= $(GNL_SRC:%.c=%.o)

CC 			= cc

CFLAGS		= -Wextra -Wall -Werror

HEADERS		= -Imlx -Iprintf -Ilibft -Ignl -I.

LIBRARIES	= -Lmlx -lmlx -L./printf -lftprintf -L./libft -lft \
			  -lXext -lX11 -lm -lz

all			: makelib $(NAME)

$(NAME)		: $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

%.o			: %.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

makelib		:
	make -C mlx
	make -C printf
	make -C libft

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
	
re			: fclean all clean makelib
