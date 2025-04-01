# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/01 19:02:00 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all			: up

update-env	:
	echo "USER_PWD=$$(cat secrets/db_password.txt)" >> srcs/.env
	echo "ADM_PWD=$$(cat secrets/db_admin_password.txt)" >> srcs/.env
	echo "ROOT_PWD=$$(cat secrets/db_root_password.txt)" >> srcs/.env

remove-env	:
	sed -i '/^USER_PWD=/d' srcs/.env
	sed -i '/^ADM_PWD=/d' srcs/.env
	sed -i '/^ROOT_PWD=/d' srcs/.env

up			: update-env
	docker compose -f ./srcs/docker-compose.yml up -d

down		: remove-env
	docker compose -f ./srcs/docker-compose.yml down

fdown		: remove-env
	docker compose -f ./srcs/docker-compose.yml down --rmi all -v

re			: fdown up

start		:
	docker compose -f ./srcs/docker-compose.yml start

stop		:
	docker compose -f ./srcs/docker-compose.yml stop

.PHONY			: all up start stop
