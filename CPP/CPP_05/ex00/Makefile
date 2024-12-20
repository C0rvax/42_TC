# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2024/11/12 16:57:26 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				= c++

CXXFLAGS			= -Wall -Wextra -Werror -std=c++98

OBJ				= $(SRC:.cpp=.o)

HEADERS			= -I./include

SRC				= main.cpp 								\
				  Bureaucrat.cpp

NAME			= Bureaucrat

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
