#!/bin/bash

mkdir -p /var/run/vsftpd/empty

# Créer un utilisateur et définir son mot de passe
if ! id "$FTP_USER" &>/dev/null; then
    adduser --home /home/$FTP_USER --disabled-password --gecos "" $FTP_USER
    echo "$FTP_USER:$FTP_PWD" | /usr/sbin/chpasswd
    echo "$FTP_USER" | tee -a /etc/vsftpd.userlist
fi

usermod -aG www-data $FTP_USER

unset USER_PWD ADM_PWD ROOT_PWD WP_PWD REDIS_PWD FTP_PWD

exec /usr/sbin/vsftpd /etc/vsftpd.conf
