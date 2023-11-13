GNL_DIR = $(shell dirname $(shell pwd))/GNL/
LIBFT_DIR = $(shell dirname $(shell pwd))/libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I. -I$(GNL_DIR) -I$(LIBFT_DIR)
SRC = $(GNL_DIR)get_next_line.c
MAIN = main.c
UTIL = 

all:	verif
	@$(CC) $(CFLAGS) $(HEADERS) $(SRC) $(MAIN) -L$(LIBFT_DIR) -lft		\
		&& ./a.out && rm -rf a.out

verif:
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR) && $(RM) a.out*

fclean:
	make fclean -C $(LIBFT_DIR) && $(RM) a.out*
