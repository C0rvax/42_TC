# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2024/10/30 23:29:10 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= main.cpp 								\
				  ClapTrap.cpp							\
				  ScavTrap.cpp							\
				  FragTrap.cpp

OBJ				= $(SRC:.cpp=.o)

CXX				= c++

CXXFLAGS			= -Wall -Wextra -Werror -std=c++98

NAME			= frag

all				: $(NAME)

$(NAME)			: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ -I.

%.o				: %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@ -I.

clean			:
	rm -rf $(OBJ) $(OBJ:.o=.d)

fclean			: clean
	rm -rf $(NAME)

re				: fclean all

-include $(OBJ:.o=.d)

.PHONY			: all clean fclean re
