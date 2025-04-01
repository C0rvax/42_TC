#!/bin/bash

cd /var/www/html

USER_PWD=$(cat db_password.txt)
USER_PWD=$(cat db_admin_password.txt)

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp # Use wp instead of wp-cli...
wp core download --allow-root
wp config create --dbname=wordpress --dbuser=$MYSQL_USER --dbpass=$USER_PWD --dbhost=mariadb --allow-root
wp core install --url=$DOMAIN_NAME/ --title=$TITLE --admin_user=$ADM --admin_password=$ADM_PWD --admin_email=$EMAIL --skip-email --allow-root

rm -rf db_password.txt db_admin_password.txt

cd

mkdir /run/php

php-fpm7.4 -F
