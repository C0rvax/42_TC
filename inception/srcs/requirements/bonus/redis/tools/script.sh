#!/bin/bash

mkdir -p /var/www/html/data
echo "
protected-mode yes

port 6379

daemonize no

loglevel notice

dir /var/www/html/data

maxmemory 512mb

maxmemory-policy allkeys-lru

requirepass $REDIS_PWD" >/etc/redis/redis.conf

unset USER_PWD ADM_PWD ROOT_PWD WP_PWD REDIS_PWD FTP_PWD

sysctl vm.overcommit_memory=1

exec redis-server /etc/redis/redis.conf
