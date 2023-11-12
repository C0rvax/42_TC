LIBFT_DIR = $(shell dirname $(shell pwd))/libft
MAIN_DIR = main/
CC = cc
RM = rm -rf
OUT = a.out
UTIL = display.c
CFLAGS = -I$(LIBFT_DIR) -I. $(UTIL)

FIXE = strlen atoi isalpha isascii isalnum isdigit isprint tolower toupper	\
	   bzero memchr memcmp memcpy memmove memset split
BONUS = 

$(FIXE): %:		verif
	@$(CC) $(CFLAGS) $(MAIN_DIR)$*_t.c -L$(LIBFT_DIR) -lft && ./$(OUT) 		\
	&& $(RM) $(OUT)

$(BONUS): %:	verif
	@$(CC) $(CFLAGS) $(MAIN_DIR)$*_t.c -L$(LIBFT_DIR) -lft && ./$(OUT)		\
	&& $(RM) $(OUT)

verif:		checklib
	make -C $(LIBFT_DIR)

checklib:
	@ls $(LIBFT_DIR) | grep Makefile > /dev/null 2>&1 || echo où est le Makefile

f: $(FIXE)
b: $(BONUS)
a: f b

clean:
	make clean -C $(LIBFT_DIR) && $(RM) $(OUT)*

fclean:
	make fclean -C $(LIBFT_DIR) && $(RM) $(OUT)*
