CC			= cc

NAME		= push_swap

BONUS_NAME	= checker

DIR			= ./src/

GNL_DIR		= ./gnl/

BONUS_DIR	= ./bonus/

FILE			= main.c check_list.c sort_list.c exec.c list.c utils.c		\
			  find_index.c all_in.c rotate.c get_q.c

FILE_BONUS	= main_bonus.c check_list.c list.c exec_instructions.c			\
			  utils_bonus.c rotate_bonus.c instructions.c

FILE_GNL	= get_next_line.c get_next_line_utils.c

SRC			= $(addprefix $(DIR), $(FILE))

SRC_BONUS	= $(addprefix $(BONUS_DIR), $(FILE_BONUS)) 

SRC_GNL		= $(addprefix $(GNL_DIR), $(FILE_GNL))

OBJ			:= $(SRC:.c=.o)

OBJ_GNL		:= $(SRC_GNL:.c=.o)

OBJ_BONUS	:= $(SRC_BONUS:.c=.o)

CFLAGS		= -Wextra -Wall -Werror

HEADERS		= -I./include

LIBRARIES	= -L./printf -lftprintf -L./libft -lft

all			: $(NAME)

$(NAME)		: $(OBJ) $(OBJ_GNL)
		make -C printf
		make -C libft
		$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

%.o			: %.c
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

bonus		: $(OBJ_BONUS) $(OBJ_GNL)
		make -C printf
		make -C libft
		$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $(BONUS_NAME)

clean		:
		rm -f $(OBJ) $(OBJ_GNL) $(OBJ_BONUS)
		make clean -C printf
		make clean -C libft

fclean		: clean
		rm -f $(NAME) $(BONUS_NAME)
		make fclean -C printf
		make fclean -C libft

re			: fclean all

.PHONY		: all clean fclean re bonus
