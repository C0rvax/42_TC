FROM debian:bullseye

RUN apt update && apt upgrade && apt install\
	nginx -y\
	vim -y\
	curl -y\
	OpenSSL -y\

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=aduvilla.42.fr/UID=aduvilla"

RUN mkdir -p /var/run/nginx
