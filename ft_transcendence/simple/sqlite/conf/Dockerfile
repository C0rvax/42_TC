FROM alpine:latest

RUN apk --no-cache add sqlite

WORKDIR /db

#COPY initial-db.sqlite /db/
COPY init.sql /db/

CMD ["sqlite3", "/data/initial-db.sqlite"]
