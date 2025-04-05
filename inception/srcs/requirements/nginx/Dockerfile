FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y nginx openssl procps \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/nginx.conf /etc/nginx/sites-available/default

RUN mkdir -p /var/www/static_site
COPY ./static/index.html /var/www/static/index.html
COPY ./static/style.css /var/www/static/style.css

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
