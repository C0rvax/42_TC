# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2024/10/02 12:58:24 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= main.cpp 								\
				  Zombie.cpp							\
				  newZombie.cpp							\
				  randomChump.cpp						

OBJ				= $(SRC:.cpp=.o)

CC				= c++

FLAGS			= -Wall -Wextra -Werror -std=c++98

NAME			= Zombie

all				: $(NAME)

$(NAME)			: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o				: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean			:
	rm -rf $(OBJ)

fclean			: clean
	rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
