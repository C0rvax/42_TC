# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/04 10:21:08 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENV_FILE	= srcs/.env

TEMP_ENV	= srcs/.env.bak

CREDENTIALS	= secrets/credentials.txt \
			  secrets/db_password.txt \
			  secrets/db_admin_password.txt \
			  secrets/db_root_password.txt \
			  secrets/wp_user_password.txt

all			: up

update-env	:
	@cat $(CREDENTIALS) >> $(ENV_FILE)

remove-env	:
	@cat $(CREDENTIALS) > $(TEMP_ENV)
	@grep -Fvx -f $(TEMP_ENV) $(ENV_FILE) > $(ENV_FILE).tmp && mv $(ENV_FILE).tmp $(ENV_FILE)
	@rm -f $(TEMP_ENV)
#	sed -i '/^USER_PWD=/d' srcs/.env
#	sed -i '/^ADM_PWD=/d' srcs/.env
#	sed -i '/^ROOT_PWD=/d' srcs/.env

up			: update-env
	mkdir -p ~/data/mariadb ~/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d

down		: remove-env
	docker compose -f ./srcs/docker-compose.yml down

fdown		: remove-env
	sudo rm -rf ~/data
	docker compose -f ./srcs/docker-compose.yml down --rmi all -v

logs		:
	docker compose -f ./srcs/docker-compose.yml logs

re			: fdown up

stop		:
	docker compose -f ./srcs/docker-compose.yml stop

.PHONY			: all up update-env remove-env down fdown logs re stop
