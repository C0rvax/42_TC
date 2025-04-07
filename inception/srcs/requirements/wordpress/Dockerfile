FROM debian:bullseye

RUN apt-get update -y \
	&& apt-get install -y curl php7.4-fpm php-mysqli \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/wordpress.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY --chmod=0755 ./tools/script.sh /usr/local/bin/

CMD ["/usr/local/bin/script.sh"]


# FROM alpine:3.20
#
# ARG PHP_VERSION=83
#
# RUN apk update && \
#     apk add --no-cache \
#         curl \
#         # Core PHP, FPM, CLI et extensions
#         php${PHP_VERSION} \
#         php${PHP_VERSION}-fpm \
#         php${PHP_VERSION}-cli \
#         php${PHP_VERSION}-mysqli \
#         php${PHP_VERSION}-gd \
#         php${PHP_VERSION}-intl \
#         php${PHP_VERSION}-mbstring \
#         php${PHP_VERSION}-curl \
#         php${PHP_VERSION}-dom \
#         php${PHP_VERSION}-xml \
#         php${PHP_VERSION}-zip \
#         php${PHP_VERSION}-opcache \
#         php${PHP_VERSION}-session \
#         php${PHP_VERSION}-json \
#         php${PHP_VERSION}-phar
#
# WORKDIR /var/www/html
#
# COPY ./conf/wordpress.conf /etc/php${PHP_VERSION}/php-fpm.d/www.conf
#
# COPY --chmod=0755 ./tools/script.sh /usr/local/bin/script.sh
#
# # Définir la commande par défaut pour démarrer le conteneur
# CMD ["sh", "/usr/local/bin/script.sh"]

# FROM alpine:3.16
#
# ENV PHPIZE_DEPS="autoconf dpkg-dev dpkg file g++ gcc libc-dev make pkgconf re2c musl-dev openssl-dev php8-pear php8-dev"
#
# RUN apk add --no-cache php8 \
# 	php8-dom \
# 	php8-fpm \
# 	php8-ftp \
# 	php8-gd \
# 	php8-openssl \
# 	php8-phar \
# 	php8-iconv \
# 	php8-mbstring \
# 	php8-mysqli \
# 	php8-tokenizer \
# 	php8-zlib \
# 	mariadb-client
#
# RUN apk --no-cache add $PHPIZE_DEPS \
# 	&& pecl install -o -f redis \
# 	&& rm -rf /tmp/pear \
# 	&& apk del --no-cache $PHPIZE_DEPS
#
# RUN ln -s /usr/sbin/php-fpm8 /usr/sbin/php-fpm
#
# RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -O /tmp/wp-cli.phar
# RUN mv /tmp/wp-cli.phar /usr/local/bin/wp
# RUN chmod +x /usr/local/bin/wp
#
# COPY conf/wordpress.conf /etc/php8/php-fpm.d/www.conf
# COPY tools/script.sh /usr/local/bin/
#
# EXPOSE 9000
# ENTRYPOINT ["sh", "/usr/local/bin/script.sh"]
# CMD ["php-fpm", "-F"]
