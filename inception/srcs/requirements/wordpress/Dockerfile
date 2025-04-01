FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y && apt-get install php-fpm -y

COPY ./conf/wordpress.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/script.sh .

RUN chmod +x script.sh

CMD ["./script.sh"]

#RUN mkdir -p /etc/nginx/ssl

#RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=aduvilla.42.fr/UID=aduvilla"

#RUN mkdir -p /var/run/nginx
