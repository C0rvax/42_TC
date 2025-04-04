FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
    && apt-get install -y nginx

COPY ./html /var/www/html

CMD ["nginx", "-g", "daemon off;"]
