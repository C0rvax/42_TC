FROM debian:bullseye

#RUN apt-get update -y && apt-get upgrade -y \##
RUN apt-get update -y \
	&& apt-get install -y vsftpd \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/vsftpd.conf /etc/vsftpd.conf

COPY ./tools/script.sh .
RUN chmod +x script.sh

CMD ["./script.sh"]
