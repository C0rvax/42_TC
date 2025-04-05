FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y curl php7.4-fpm php-mysqli \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/wordpress.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
