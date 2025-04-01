# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/01 14:27:36 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all			: up

up			:
	docker compose -f ./srcs/docker_compose.yml up -d

start		:
	docker compose -f ./srcs/docker_compose.yml start

stop		:
	docker compose -f ./srcs/docker_compose.yml stop

.PHONY			: all up start stop
