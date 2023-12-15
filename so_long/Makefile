NAME		= so_long

SRC			= $(addprefix src/, main.c)

OBJ := $(SRC:%.c=%.o)

CC 			= gcc

CFLAGS		= -Wextra -Wall #-Werror

all			: $(NAME)

$(NAME)		: $(OBJ)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -Llib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o			: %.c mmlx
	$(CC) $(CFLAGS) -Imlx -Iheaders -O3 -c $< -o $@

mmlx		:
	make -C mlx

clean		:
	rm -f $(OBJ)

fclean		: clean
	make clean -C mlx/
	rm -f $(NAME)
	
re			: fcleam all

