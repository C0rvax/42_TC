#!/bin/bash

mkdir -p /etc/nginx/ssl

sed -i "s|\$DOMAIN_NAME|$DOMAIN_NAME|g" $NGINX_CONF_FILE
sed -i "s|\$SSL_CERT|$SSL_CERT|g" $NGINX_CONF_FILE
sed -i "s|\$SSL_KEY|$SSL_KEY|g" $NGINX_CONF_FILE

# Output a self-signed cert instead of a cert request (x509) with no encryption (nodes)
if [ ! -f "$SSL_KEY" ] || [ ! -f "$SSL_CERT" ]; then
	openssl req -x509 -nodes \
		-newkey rsa:2048 \
		-keyout ${SSL_KEY} \
		-out ${SSL_CERT} \
		-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=${DOMAIN_NAME}"
fi

mkdir -p /var/www/html/static
if [ -f "/index.html" ] && [ -f "/style.css" ]; then
	mv /index.html /var/www/html/static/index.html
	mv /style.css /var/www/html/static/style.css
fi

unset USER_PWD ADM_PWD ROOT_PWD WP_PWD REDIS_PWD FTP_PWD

exec nginx -g "daemon off;"
#exec $@
