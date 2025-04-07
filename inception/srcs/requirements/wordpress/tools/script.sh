#!/bin/bash

cd /var/www/html
rm -rf * # clean
if [ ! -f /var/www/html/wp-config.php ]; then
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

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
fi

chown -R www-data:www-data /var/www/html/
chmod -R g+w /var/www/html/

#chown -R www-data:www-data /var/www/html/wp-content
#chmod -R g+w /var/www/html/wp-content

unset USER_PWD ADM_PWD ROOT_PWD WP_PWD REDIS_PWD FTP_PWD

cd

mkdir -p /run/php

exec php-fpm7.4 -F

# #!/bin/sh
#
# PHP_VERSION=83
# # Le WORKDIR est déjà /var/www/html (défini dans le Dockerfile)
# # cd /var/www/html # N'est plus nécessaire
#
# # Nettoyer uniquement si wp-config.php n'existe pas (évite de tout réinstaller au redémarrage)
# if [ ! -f /var/www/html/wp-config.php ]; then
#     echo "Première installation : Téléchargement de WordPress et configuration..."
#
#     # Nettoyer le répertoire (attention si vous avez des thèmes/plugins custom pré-placés)
#     rm -rf * # Soyez prudent avec cette commande si vous montez des volumes ici.
#
#     # Télécharger WP-CLI
#     curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
#     chmod +x wp-cli.phar
#     mv wp-cli.phar /usr/local/bin/wp
#
#     wp core download --allow-root
#
#     wp config create --dbname=$DB_NAME --dbuser=$MYSQL_USER --dbpass=$USER_PWD --dbhost=mariadb --allow-root --skip-check
#     wp core install --url="${DOMAIN_NAME%/}" --title="$TITLE" --admin_user="$WP_ADM" --admin_password="$ADM_PWD" --admin_email="$WP_ADM_EMAIL" --skip-email --allow-root
#     wp user create "$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_PWD" --allow-root
#
#     # Configurer Redis dans wp-config.php
#     wp config set FS_METHOD direct --allow-root --type=constant
#     wp config set WP_REDIS_HOST redis --allow-root --type=constant
#     wp config set WP_REDIS_PORT 6379 --allow-root --type=constant --raw # Port is numeric
#     wp config set WP_REDIS_PASSWORD "$REDIS_PWD" --allow-root --type=constant
#
#     # Installer et activer le plugin Redis
#     wp plugin install redis-cache --activate --allow-root
#     wp redis enable --allow-root
#
#
#     chown -R www-data:www-data /var/www/html/
#     chmod -R g+w /var/www/html/
#
#     # chown -R www-data:www-data /var/www/html/wp-content
#     # chmod -R g+w /var/www/html/wp-content
# fi
#
# unset USER_PWD ADM_PWD ROOT_PWD WP_PWD REDIS_PWD FTP_PWD
#
# mkdir -p /run/php
#
# exec php-fpm${PHP_VERSION} -F --pid /run/php/php-fpm.pid

# ALREADY_EXISTS='false'
# DATADIR='/wp'
#
# main() {
# 	if [ -f "$DATADIR/wp-config.php" ]; then
# 		ALREADY_EXISTS='true'
# 	fi
#
# 	if [ "$ALREADY_EXISTS" = 'false' ]; then
# 		echo "Waiting for database..."
# 		echo "Database is ready."
# 		echo "Installing Wordpress..."
#
# 		wget -q -O - https://wordpress.org/latest.tar.gz | tar -xz -C /wp --strip-components=1
# 		#chmod -R +rwx /wp
#
# 		wp --path=$DATADIR config create --dbname=$DB_NAME --dbuser=$MYSQL_USER --dbpass=$USER_PWD --dbhost=mariadb --allow-root --skip-check
# 		wp --path=$DATADIR core install --url="${DOMAIN_NAME%/}" --title="$TITLE" --admin_user="$WP_ADM" --admin_password="$ADM_PWD" --admin_email="$WP_ADM_EMAIL" --skip-email --allow-root
# 		wp --path=$DATADIR user create "$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_PWD" --allow-root
#
# 		# SETUP REDIS
# 		wp --path=$DATADIR set FS_METHOD direct --allow-root --type=constant
# 		wp --path=$DATADIR config set WP_CACHE "true" --raw
# 		wp --path=$DATADIR set WP_REDIS_HOST redis --allow-root --type=constant
# 		wp --path=$DATADIR config set WP_REDIS_PORT 6379 --allow-root --type=constant --raw # Port is numeric
# 		wp --path=$DATADIR plugin install redis-cache --activate
# 		wp --path=$DATADIR redis enable
#
# 		echo -e "\nWordpress installation done. Ready for start up.\n"
# 	else
# 		echo "Wordpress is already installed"
# 	fi
#
# 	chmod -R 777 $DATADIR
# 	echo "Starting PHP-FPM..."
# 	exec "$@"
# }
#
# if [ "$1" = 'php-fpm' ]; then
# 	main $@
# else
# 	exec "$@"
# fi
