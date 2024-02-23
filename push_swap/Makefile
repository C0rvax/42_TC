CC			= cc

NAME		= push_swap

BONUS_NAME	= checker

vpath %.c src/ gnl/

SRC			= main.c check_list.c sort_list.c exec.c list.c utils.c			\
			  find_index.c all_in.c rotate.c

SRC_BONUS	= main_bonus.c check_list.c list.c rotate.c

GNL_SRC		= get_next_line.c get_next_line_utils.c

OBJ			:= $(SRC:%.c=%.o)

OBJ_BONUS	:= $(SRC_BONUS:%.c=%.o)

CFLAGS		= -Wextra -Wall -Werror

HEADERS		= -I./include

LIBRARIES	= -L./printf -lftprintf -L./libft -lft

all			: $(NAME)

$(NAME)		: $(OBJ) $(GNL_OBJ)
		make -C printf
		make -C libft
		$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

%.o			: %.c
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

bonus		: $(OBJ_BONUS) $(GNL_OBJ)
		make -C printf
		make -C libft
		$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $(BONUS_NAME)

clean		:
		rm -f $(OBJ) $(GNL_OBJ) $(OBJ_BONUS)
		make clean -C printf
		make clean -C libft

fclean		: clean
		rm -f $(NAME) $(BONUS_NAME)
		make fclean -C printf
		make fclean -C libft

re			: fclean all

.PHONY		: all clean fclean re bonus
