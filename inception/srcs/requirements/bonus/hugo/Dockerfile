FROM alpine:3.20

RUN apk update && apk add --update --no-cache \
    hugo \
    git \
    shadow \
    && rm -f /var/cache/apk/*

RUN hugo new site /var/hugo/static

WORKDIR /var/hugo/static

COPY ./conf/ .

CMD ["hugo", "server", "--bind=0.0.0.0", "--baseURL=https://aduvilla.42.fr/hugo/", "-p", "8800", "--appendPort=false"]
