# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/02/05 19:55:14 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				= c++

CXXFLAGS			= -Wall -Wextra -Werror -std=c++98

OBJ				= $(SRC:.cpp=.o)

HEADERS			= -I./include

SRC				= main.cpp 								\
				  Bureaucrat.cpp						\
				  AForm.cpp								\
				  PresidentialPardonForm.cpp			\
				  ShrubberyCreationForm.cpp				\
				  RobotomyRequestForm.cpp				\
				  Intern.cpp

NAME			= intern

all				: $(NAME)

$(NAME)			: $(OBJ)
	$(CXX) $(CXXLAGS) $^ -o $@

%.o				: src/%.cpp
	$(CXX) -MMD $(CXXFLAGS) $(HEADERS) -c $< -o $@

clean			:
	rm -rf $(OBJ) $(OBJ:.o=.d)

fclean			: clean
	rm -rf $(NAME)

re				: fclean all

-include $(OBJ:.o=.d)

.PHONY			: all clean fclean re
