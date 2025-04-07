# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/07 15:46:45 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENV_FILE	= srcs/.env

TEMP_ENV	= srcs/.env.bak

DC_FILE		= ./srcs/docker-compose.yml

CREDENTIALS	= secrets/credentials.txt \
			  secrets/passwords.txt
#			  secrets/db_user_pwd.txt \
#			  secrets/db_root_pwd.txt \
#			  secrets/wp_admin_pwd.txt \
#			  secrets/wp_user_pwd.txt \
#			  secrets/redis_pwd.txt \
#			  secrets/gf_pwd.txt \
#			  secrets/ftp_pwd.txt

all			: up

up		:
	@cat $(CREDENTIALS) >> $(ENV_FILE)
	@mkdir -p ~/data/mariadb ~/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d
	@cat $(CREDENTIALS) > $(TEMP_ENV)
	@grep -Fvx -f $(TEMP_ENV) $(ENV_FILE) > $(ENV_FILE).tmp && mv $(ENV_FILE).tmp $(ENV_FILE)
	@rm -f $(TEMP_ENV)

ps		:
	@echo "<<< Showing processes (ps aux) in all containers >>>"
	@docker compose -f $(DC_FILE) config --services | xargs -I {} sh -c 'echo; \
	echo "--------------------------------------------------"; \
	echo "    --- Processes in Container: {} ---"; \
	echo "--------------------------------------------------"; \
	docker exec -t {} ps aux || echo "Error executing ps in {}"; \
	echo "--------------------------------------------------";'
	@echo

down		:
	docker compose -f $(DC_FILE) down

fdown		:
	@sudo rm -rf ~/data
	docker compose -f $(DC_FILE) down --rmi all -v

prune		: fdown
	docker system prune -a --volumes --force

logs		:
	docker compose -f $(DC_FILE) logs

restart		:
	docker compose -f $(DC_FILE) restart

stop		:
	docker compose -f $(DC_FILE) stop

.PHONY			: all up down fdown prune logs re stop
