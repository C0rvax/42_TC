FROM debian:bullseye

RUN apt-get update -y \
	&& apt-get install -y nginx openssl procps \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/default.conf /etc/nginx/sites-available/default

COPY ./static/ .

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]

# FROM alpine:3.20
#
# RUN apk update && \
#     apk add --no-cache \
#         nginx \
#         openssl \
#         procps
#
# #COPY conf/nginx.conf /etc/nginx/sites-available/default
# COPY conf/nginx.conf /etc/nginx/nginx.conf
# COPY conf/default.conf /etc/nginx/conf.d/default.conf
#
# COPY static/ .
#
# COPY tools/script.sh /script.sh
# RUN chmod +x /script.sh
#
# CMD ["sh", "/script.sh"]
