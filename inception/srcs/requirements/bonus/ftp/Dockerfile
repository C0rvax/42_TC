FROM debian:bullseye

RUN apt-get update -y \
	&& apt-get install -y vsftpd \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/vsftpd.conf /etc/vsftpd.conf

COPY --chmod=0755 ./tools/script.sh /usr/local/bin/

CMD ["/usr/local/bin/script.sh"]
