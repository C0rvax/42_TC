NAME		= so_long

SRC			= $(addprefix src/, main.c)

OBJ := $(SRC:%.c=%.o)

CC 			= gcc

CFLAGS		= -Wextra -Wall #-Werror

HEADERS		= -Imlx -Iprintf -Ilibft 

LIBRARIES	= -Lmlx -lmlx -Lprintf -l:libftprintf.a -Llibft -l:libft.a		\
	-lXext -lX11 -lm -lz -lft

all			: $(NAME)

$(NAME)		: $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBRARIES) -Imlx -o $(NAME)

%.o			: %.c makelib
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

makelib		:
	make -C mlx
	make -C printf
	make -C libft

clean		:
	rm -f $(OBJ)

fclean		: clean
	make clean -C mlx
	make clean -C printf
	make clean -C libft
	rm -f $(NAME)
	
re			: fcleam all

