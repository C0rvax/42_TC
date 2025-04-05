FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y redis-server procps \
	&& rm -rf /var/lib/apt/lists/*

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
