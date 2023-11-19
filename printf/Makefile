LDIR = libft/

CC = cc
AR = ar rc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I. -I$(LDIR)

NAME = libftprintf.a

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	$(AR) $(NAME) $?

makelibft:
	make -C $(LDIR)



