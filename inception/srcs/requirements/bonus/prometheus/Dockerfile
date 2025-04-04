FROM debian:bullseye

# Installer les dépendances nécessaires
RUN apt-get update -y && apt-get upgrade -y \
    && apt-get install -y wget

# Télécharger Prometheus
RUN wget https://github.com/prometheus/prometheus/releases/download/v2.44.0/prometheus-2.44.0.linux-amd64.tar.gz \
    && tar -zxvf prometheus-2.44.0.linux-amd64.tar.gz \
    && mv prometheus-2.44.0.linux-amd64 /usr/local/prometheus

# Copier la configuration de Prometheus (à ajouter plus tard)
COPY ./conf/prometheus.yml /usr/local/prometheus/prometheus.yml

# Exposer le port pour Prometheus
#EXPOSE 9090

# Commande pour démarrer Prometheus
CMD ["/usr/local/prometheus/prometheus", "--config.file=/usr/local/prometheus/prometheus.yml"]

