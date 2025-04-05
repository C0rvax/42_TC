FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    curl \
    ca-certificates \
    docker.io \
    && rm -rf /var/lib/apt/lists/*

# Installer Portainer
RUN curl -L https://github.com/portainer/portainer/releases/download/2.16.1/portainer-2.16.1-linux-amd64.tar.gz -o portainer.tar.gz \
    && tar -xzf portainer.tar.gz \
    && mv portainer/portainer /usr/local/bin/portainer \
    && rm -rf portainer.tar.gz portainer

# Installer Docker Compose v2
RUN mkdir -p /usr/libexec/docker/cli-plugins && \
    curl -SL https://github.com/docker/compose/releases/download/v2.27.1/docker-compose-linux-x86_64 \
    -o /usr/libexec/docker/cli-plugins/docker-compose && \
    chmod +x /usr/libexec/docker/cli-plugins/docker-compose

EXPOSE 9000
VOLUME ["/data"]

CMD ["/usr/local/bin/portainer", "--bind", "0.0.0.0:9000"]
