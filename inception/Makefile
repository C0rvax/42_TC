# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/02 13:11:13 by aduvilla         ###   ########.fr        #
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

logs		:
	docker compose -f ./srcs/docker-compose.yml logs

re			: fdown up

stop		:
	docker compose -f ./srcs/docker-compose.yml stop

.PHONY			: all up update-env remove-env down fdown logs re stop
