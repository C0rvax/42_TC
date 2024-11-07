# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2024/11/07 11:39:01 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= c++

FLAGS			= -Wall -Wextra -Werror -std=c++98

OBJ				= $(SRC:.cpp=.o)

HEADERS			= -I./include

SRC				= main.cpp 								\
				  Dog.cpp								\
				  AAnimal.cpp							\
				  Cat.cpp								\
				  WrongAnimal.cpp						\
				  WrongCat.cpp							\
				  Brain.cpp

NAME			= Abstract

all				: $(NAME)

$(NAME)			: $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o				: %.cpp
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

clean			:
	rm -rf $(OBJ)

fclean			: clean
	rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re

