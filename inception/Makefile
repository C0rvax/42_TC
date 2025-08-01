# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:29:59 by aduvilla          #+#    #+#              #
#    Updated: 2025/04/09 19:11:15 by aduvilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENV_FILE	= srcs/.env

DC_FILE		= ./srcs/docker-compose.yml

CREDENTIALS	= secrets/credentials.txt

all			: up

up			:
	@grep -Fvx -f $(CREDENTIALS) $(ENV_FILE) > $(ENV_FILE).tmp || true
	@cat $(CREDENTIALS) >> $(ENV_FILE).tmp
	@mv $(ENV_FILE).tmp $(ENV_FILE)
	@mkdir -p ~/data/mariadb ~/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d
	@grep -Fvx -f $(CREDENTIALS) $(ENV_FILE) > $(ENV_FILE).tmp || true
	@mv $(ENV_FILE).tmp $(ENV_FILE)

down		:
	docker compose -f $(DC_FILE) down

re			: down up

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

ps			:
	@echo "<<< Showing processes (ps aux) in all containers >>>"
	@docker compose -f $(DC_FILE) config --services | xargs -I {} sh -c 'echo; \
	echo "--------------------------------------------------"; \
	echo "    --- Processes in Container: {} ---"; \
	echo "--------------------------------------------------"; \
	docker exec -t {} ps aux || echo "Error executing ps in {}"; \
	echo "--------------------------------------------------";'
	@echo

cert		:
	bash ./srcs/requirements/tools/copyCert.sh

.PHONY		: all up down fdown prune logs re stop ps
