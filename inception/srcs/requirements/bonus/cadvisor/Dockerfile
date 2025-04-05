FROM  debian:bullseye

RUN apt-get update && apt-get install -y wget \
	&& rm -rf /var/lib/apt/lists/*

# Téléchargement de la bonne version de cAdvisor
RUN wget https://github.com/google/cadvisor/releases/download/v0.44.0/cadvisor && \
    chmod +x cadvisor && \
    mv cadvisor /usr/local/bin/cadvisor

# Commande pour démarrer cAdvisor
CMD ["/usr/local/bin/cadvisor", "-port=8080"]
