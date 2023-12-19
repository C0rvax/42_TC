NAME		= so_long

SRC			= $(addprefix src/, main.c initiate.c main_loop.c display.c		\
			  display_back.c move.c)

GNL_SRC		= $(addprefix gnl/, get_next_line.c get_next_line_utils.c)

OBJ			:= $(SRC:%.c=%.o)

GNL_OBJ		:= $(GNL_SRC:%.c=%.o)

CC 			= gcc

CFLAGS		= -Wextra -Wall #-Werror

HEADERS		= -Imlx -Iprintf -Ilibft -Ignl -I.

LIBRARIES	= -Lmlx -lmlx printf/ft_printf.a libft/libft.a 			\
			  -lXext -lX11 -lm -lz

all			: $(NAME)

$(NAME)		: $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $^ $(LIBRARIES) -Imlx -o $@

%.o			: %.c makelib
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
	
re			: fclean all

