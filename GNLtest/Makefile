GNL_DIR = $(shell dirname $(shell pwd))/GNL/
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I $(GNL_DIR)
SRC = $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c
MAIN = main.c
UTIL = 

all:
	@$(CC) $(CFLAGS) $(HEADERS) $(SRC) $(MAIN) && valgrind ./a.out		\
		&& rm -rf a.out

clean:
	@make clean -C $(LIBFT_DIR) && $(RM) a.out*

fclean:
	@make fclean -C $(LIBFT_DIR) && $(RM) a.out*
