#!/bin/bash

# Créer le répertoire /var/run/vsftpd/empty si il n'existe pas
mkdir -p /var/run/vsftpd/empty

service vsftpd start

# Créer un utilisateur et définir son mot de passe
adduser $FTP_USER --disabled-password

echo "$FTP_USER:$FTP_PWD" | /usr/sbin/chpasswd

echo "$FTP_USER" | tee -a /etc/vsftpd.userlist

# Créer les dossiers nécessaires
mkdir -p /home/$FTP_USER/ftp/files/themes/custom

# Configurer les permissions
chown $FTP_USER:$FTP_USER /home/$FTP_USER/ftp
chmod 755 /home/$FTP_USER/ftp
chown $FTP_USER:$FTP_USER /home/$FTP_USER/ftp/files

# Redémarrer le service vsftpd
service vsftpd stop

exec /usr/sbin/vsftpd /etc/vsftpd.conf
