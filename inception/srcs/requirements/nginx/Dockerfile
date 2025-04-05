FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y nginx openssl procps \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/nginx.conf /etc/nginx/sites-available/default

# Crée un dossier pour le site statique et copie les fichiers dedans
RUN mkdir -p /var/www/static_site
COPY ./html/index.html /var/www/static_site/index.html
COPY ./html/style.css /var/www/static_site/style.css

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
