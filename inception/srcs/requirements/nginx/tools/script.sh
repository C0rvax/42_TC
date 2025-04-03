#!/bin/bash

mkdir -p /etc/nginx/ssl
#!/bin/bash

# Replace with env values
sed -i "s|\$DOMAIN_NAME|$DOMAIN_NAME|g" /etc/nginx/sites-available/default
sed -i "s|\$SSL_CERT|$SSL_CERT|g" /etc/nginx/sites-available/default
sed -i "s|\$SSL_KEY|$SSL_KEY|g" /etc/nginx/sites-available/default

# Output a self-signed cert instead of a cert request (x509) with no encryption (nodes)
openssl req -x509 -nodes \
	-newkey rsa:2048 \
	-keyout ${SSL_KEY} \
	-out ${SSL_CERT} \
	-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=${DOMAIN_NAME}"

unset USER_PWD ADM_PWD ROOT_PWD

nginx -g "daemon off;"
