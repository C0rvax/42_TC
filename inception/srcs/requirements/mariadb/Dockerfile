FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install mariadb-server -y

RUN apt-get install netcat -y # For healthcheck

COPY ./conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/script.sh .

RUN chmod +x script.sh

CMD ["./script.sh"]
