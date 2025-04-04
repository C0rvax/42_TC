FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    curl \
    docker.io \
    && rm -rf /var/lib/apt/lists/*

# Télécharger la version de Portainer (version stable ou la plus récente)
RUN curl -L https://github.com/portainer/portainer/releases/download/2.16.1/portainer-2.16.1-linux-amd64.tar.gz -o portainer.tar.gz \
    && tar -xvzf portainer.tar.gz \
    && mv portainer/portainer /usr/local/bin/portainer \
    && rm portainer.tar.gz

# Exposer le port 9000 pour l'interface web de Portainer
EXPOSE 9000

# Créer un volume pour les données de Portainer
VOLUME ["/data"]

CMD ["/usr/local/bin/portainer", "--bind", "0.0.0.0:9000"]

