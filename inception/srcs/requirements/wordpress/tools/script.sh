#!/bin/bash

cd /var/www/html
rm -rf * # clean

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp # Use wp instead of wp-cli...

wp core download --allow-root

wp config create --dbname=$DB_NAME --dbuser=$MYSQL_USER --dbpass=$USER_PWD --dbhost=mariadb --allow-root
wp core install --url="${DOMAIN_NAME%/}" --title=$TITLE --admin_user=$WP_ADM --admin_password=$ADM_PWD --admin_email=$WP_ADM_EMAIL --skip-email --allow-root
wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_PWD --allow-root

# REDIS CONFIG
wp config set FS_METHOD direct --allow-root --type=constant
wp config set WP_REDIS_HOST redis --allow-root --type=constant
wp config set WP_REDIS_PORT 6379 --allow-root --type=constant --raw # Port is numeric
wp config set WP_REDIS_PASSWORD "$REDIS_PWD" --allow-root --type=constant

wp plugin install redis-cache --activate --allow-root
wp redis enable --allow-root

chown -R www-data:www-data /var/www/html/wp-content
chmod -R g+w /var/www/html/wp-content

unset USER_PWD ADM_PWD ROOT_PWD WP_PWD

cd

mkdir -p /run/php

exec php-fpm7.4 -F
