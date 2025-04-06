FROM debian:bullseye

RUN apt-get update && apt-get install -y wget

RUN wget https://github.com/prometheus/node_exporter/releases/download/v1.3.1/node_exporter-1.3.1.linux-amd64.tar.gz && \
    tar xvf node_exporter-1.3.1.linux-amd64.tar.gz && \
    mv node_exporter-1.3.1.linux-amd64/node_exporter /usr/local/bin/

EXPOSE 9100

CMD ["node_exporter"]
