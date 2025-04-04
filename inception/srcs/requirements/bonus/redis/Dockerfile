FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install -y redis-server

COPY ./conf/redis.conf /etc/redis/redis.conf

CMD ["redis-server"]
