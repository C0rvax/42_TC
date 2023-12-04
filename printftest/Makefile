#SRC_DIR = "../printf/"
SRC_DIR	= /home/aduvilla/Code/Rendu/ft_printf_00/
CC = cc
CFLAGS = -I$(SRC_DIR)
MAIN = main.c
SRC = $(SRC_DIR)ft_printf.c $(SRC_DIR)print_hex.c $(SRC_DIR)print_putchar.c $(SRC_DIR)print_putstr.c	\
	  $(SRC_DIR)print_pointer.c  $(SRC_DIR)print_number.c $(SRC_DIR)print_unsigned.c $(SRC_DIR)ifforest.c

RM = rm -rf

all:
	$(CC) $(CFLAGS) $(SRC) $(MAIN) && ./a.out && $(RM) a.out

clean:
	make clean -C $(SRC_DIR) && $(RM) a.out*

