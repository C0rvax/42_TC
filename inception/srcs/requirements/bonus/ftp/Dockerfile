FROM debian:bullseye

# Mettre à jour et installer vsftpd
RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install -y vsftpd

# Configurer vsftpd
COPY ./conf/vsftpd.conf /etc/vsftpd.conf

COPY ./tools/script.sh .

RUN chmod +x script.sh

CMD ["./script.sh"]
