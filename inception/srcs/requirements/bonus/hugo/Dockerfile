FROM    alpine:3.20

WORKDIR /var/hugo/static

RUN     apk update && apk upgrade && apk add --update --no-cache \
            hugo \
            git \
            shadow \
 &&     rm -f /var/cache/apk/*

RUN hugo new site /var/hugo/static \
 	&&     cd /var/hugo/static \
    &&     hugo -b https://aduvilla.42.fr/hugo


COPY ./conf/config.toml /var/hugo/static/config.toml
COPY ./conf/index.html /var/hugo/static/layouts/index.html
COPY ./conf/style.css /var/hugo/static/static/style.css


EXPOSE 8800

CMD     ["hugo", "server", "--bind=0.0.0.0", "--baseURL=https://aduvilla.42.fr/hugo", "-p", "8800", "--appendPort=false"]
