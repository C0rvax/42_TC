FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y 

RUN apt-get install -y nginx openssl

COPY ./conf/nginx.conf /etc/nginx/sites-available/default

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]

#RUN mkdir -p /var/run/nginx
