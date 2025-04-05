FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y curl php php-mysqli \
	&& rm -rf /var/lib/apt/lists/*

# Télécharger Adminer directement dans le dossier web
RUN curl -Lo /var/www/html/index.php https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php

CMD ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/html"]
