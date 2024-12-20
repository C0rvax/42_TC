# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2024/11/07 16:55:00 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				= c++

CXXFLAGS			= -Wall -Wextra -Werror -std=c++98

OBJ				= $(SRC:.cpp=.o)

HEADERS			= -I./include

SRC				= main.cpp 								\
				  AMateria.cpp							\
				  Cure.cpp								\
				  Character.cpp							\
				  Ice.cpp								\
				  MateriaSource.cpp

NAME			= ff8

all				: $(NAME)

$(NAME)			: $(OBJ)
	$(CXX) $(CXXLAGS) $^ -o $@

%.o				: %.cpp
	$(CXX) -MMD $(CXXFLAGS) $(HEADERS) -c $< -o $@

clean			:
	rm -rf $(OBJ) $(OBJ:.o=.d)

fclean			: clean
	rm -rf $(NAME)

re				: fclean all

-include $(OBJ:.o=.d)

.PHONY			: all clean fclean re
