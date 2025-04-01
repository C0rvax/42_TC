#!/bin/bash

USER_PWD=$(cat db_password.txt)
ROOT_PWD=$(cat db_root_password.txt)

echo "
CREATE DATABASE IF NOT EXISTS $DB_NAME ;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$USER_PWD' ;
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$MYSQL_USER'@'%' ;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOT_PWD' ;
FLUSH PRIVILEGES;" >/etc/mysql/init.sql

rm -rf db_password db_root_password

mkdir /run/mysqld

mysqld
#mysqld_safe
