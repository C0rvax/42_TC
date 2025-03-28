FROM debian:bullseye

RUN apt-get update -y && apt-get istall mariadb-server -y

COPY ./conf/mariadb.conf /etc/mysql/mariadb.conf.d/

COPY ./tools/script.sh .

RUN chmod +x script.sh

CMD ["./script.sh"]
