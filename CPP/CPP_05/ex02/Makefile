# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2024/11/14 14:17:30 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= c++

FLAGS			= -Wall -Wextra -Werror -std=c++98

OBJ				= $(SRC:.cpp=.o)

HEADERS			= -I./include

SRC				= main.cpp 								\
				  Bureaucrat.cpp						\
				  AForm.cpp								\
				  PresidentialPardonForm.cpp			\
				  ShrubberyCreationForm.cpp				\
				  RobotomyRequestForm.cpp

NAME			= Robo

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

