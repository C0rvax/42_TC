# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/01/22 17:56:59 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Iter

CXX				= c++

CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

HEADERS			= -Iinclude

SRCS			= $(addprefix src/, main.cpp)

OBJS			= $(addprefix .obj/, $(SRCS:.cpp=.o))

all				: $(NAME)

$(NAME)			: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(HEADERS)

.obj/%.o		: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -MMD $(CXXFLAGS) $(HEADERS) -c $< -o $@

clean			:
	rm -rf .obj

fclean			: clean
	rm -rf $(NAME)

re				: fclean all

-include $(OBJS:.o=.d)

.PHONY			: all clean fclean re
