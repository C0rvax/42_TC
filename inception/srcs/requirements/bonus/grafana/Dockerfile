FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y \
    && apt-get install -y wget adduser libfontconfig1

RUN wget https://dl.grafana.com/oss/release/grafana-8.5.5.linux-amd64.tar.gz \
    && tar -zxvf grafana-8.5.5.linux-amd64.tar.gz \
    && mv grafana-8.5.5 /usr/share/grafana

CMD ["/usr/share/grafana/bin/grafana-server", "--homepath=/usr/share/grafana"]
