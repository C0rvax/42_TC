# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/01 14:58:57 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all			: up

up			:
	docker compose -f ./srcs/docker-compose.yml up -d

down		:
	docker compose -f ./srcs/docker-compose.yml down

fdown		:
	docker compose -f ./srcs/docker-compose.yml down --rmi all -v

re			: fdown up

start		:
	docker compose -f ./srcs/docker-compose.yml start

stop		:
	docker compose -f ./srcs/docker-compose.yml stop

.PHONY			: all up start stop
