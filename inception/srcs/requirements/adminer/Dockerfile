FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install -y php7.4-fpm php-mysqli

COPY ./tools/adminer.php /var/www/html/index.php

CMD ["php-fpm7.4", "-F"]
