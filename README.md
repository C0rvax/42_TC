# Mon Cursus à l'École 42 Paris

![42 School](https://img.shields.io/badge/École_42-Paris-black?style=for-the-badge&logo=42)

Bienvenue dans le dépôt de mon parcours à l'École 42 !

Ce repository centralise l'ensemble des projets que j'ai réalisés au cours de mon cursus. L'École 42 est une formation en informatique unique, basée sur le **peer-learning** et une pédagogie par projets, qui m'a permis de développer des compétences techniques solides en programmation, administration système, et bien plus encore.

Chaque projet listé ci-dessous représente un défi relevé, des compétences acquises et des nuits de débogage acharné.

## 📚 Table des Matières

1.  [Le Tronc Commun - Les Bases du C](#le-tronc-commun---les-bases-du-c)
2.  [Le Tronc Commun - Algorithmique](#le-tronc-commun---algorithmique)
3.  [Le Tronc Commun - Graphisme](#le-tronc-commun---graphisme)
4.  [Le Tronc Commun - Système & Réseau](#le-tronc-commun---système--réseau)
5.  [La Branche C++](#la-branche-c)
6.  [Les Projets Finaux](#les-projets-finaux)

---

## Le Tronc Commun - Les Bases du C

Ces premiers projets sont les fondations de la programmation en C.

### `libft`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Le tout premier projet. Il s'agit de recréer une bibliothèque de fonctions C de base (similaires à la `<string.h>`, `<stdlib.h>`, etc.) ainsi que des fonctions de manipulation de listes chaînées.
- **Compétences acquises** : Bases du C, gestion de la mémoire (`malloc`, `free`), pointeurs, structures de données.

### `ft_printf`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Recréer la célèbre fonction `printf` de la `libc`. Un projet complexe qui demande une gestion fine des arguments et du formatage de chaînes de caractères.
- **Compétences acquises** : Fonctions variadiques, gestion de buffers, analyse de chaînes de formatage, précision et rigueur.

### `get_next_line`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Coder une fonction qui lit un fichier ligne par ligne. Un projet qui met à l'épreuve la gestion de la mémoire et l'utilisation de variables statiques.
- **Compétences acquises** : Descripteurs de fichiers, lecture de fichiers, variables statiques, gestion de la mémoire dans des contextes de lecture séquentielle.

---

## Le Tronc Commun - Algorithmique

### `push_swap`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Trier une pile de nombres en utilisant un ensemble limité d'opérations et une seconde pile auxiliaire, le tout en un minimum d'instructions.
- **Compétences acquises** : Algorithmique (radix sort, etc.), optimisation, manipulation de structures de données (piles/listes chaînées).

---

## Le Tronc Commun - Graphisme

### `so_long`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Créer un petit jeu 2D simple en utilisant la bibliothèque graphique fournie par l'école, la `MiniLibX`.
- **Compétences acquises** : Programmation graphique de base, gestion d'événements (clavier), parsing de map, boucle de jeu (game loop).

### `cub3d`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Créer un moteur 3D en "RayCasting", à la manière de *Wolfenstein 3D*. Le projet consiste à afficher une vue 3D à partir d'une carte 2D.
- **Compétences acquises** : RayCasting, trigonométrie, gestion des textures et des couleurs, optimisation graphique.

---

## Le Tronc Commun - Système & Réseau

Cette section regroupe les projets qui touchent à l'interaction avec le système d'exploitation.

### `Born2beroot`
![Shell](https://img.shields.io/badge/Tech-Shell_&_SysAdmin-lightgrey.svg?style=flat-square)

- **Description** : Installer et configurer une machine virtuelle Debian (ou CentOS) en respectant des règles de sécurité strictes : politique de mots de passe, pare-feu UFW, SSH, `sudo`, etc.
- **Compétences acquises** : Administration système Linux, virtualisation (VirtualBox), sécurité des serveurs, scripting Shell.

### `pipex`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Recréer le comportement du pipe (`|`) du shell. Ce projet est une introduction à la gestion des processus sous Unix.
- **Compétences acquises** : Processus (`fork`), communication inter-processus (`pipe`), exécution de commandes (`execve`), redirections.

### `minishell`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Le projet le plus conséquent du tronc commun. Il s'agit de créer un interpréteur de commandes (shell) capable de gérer les redirections, les pipes, les variables d'environnement, les signaux et d'exécuter des commandes.
- **Compétences acquises** : Parsing (lexing, tokenizing), gestion des processus avancée, signaux Unix, variables d'environnement, gestion des erreurs.

### `philosophers`
![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)

- **Description** : Résoudre le problème des "dîners des philosophes", un classique de la synchronisation en informatique.
- **Compétences acquises** : Multithreading, mutex, sémaphores, détection et prévention des "deadlocks" et "race conditions".

### `NetPractice`
![Network](https://img.shields.io/badge/Tech-Networking-green.svg?style=flat-square)

- **Description** : Une série d'exercices pratiques pour comprendre et configurer des réseaux TCP/IP, des sous-réseaux, des tables de routage, etc.
- **Compétences acquises** : Modèle OSI, adresses IP, masques de sous-réseau, routage, configuration réseau.

---

## La Branche C++

La découverte de la programmation orientée objet avec le C++.

### `CPP Modules 00 à 09`
![CPP](https://img.shields.io/badge/Language-C++-purple.svg?style=flat-square)

- **Description** : Une "piscine" C++ intensive répartie en 10 modules. Chaque module explore un aspect fondamental du langage.
- **Compétences acquises** :
  - **CPP00-01** : Classes, héritage, polymorphisme, références.
  - **CPP02-04** : Polymorphisme ad-hoc, classes abstraites, interfaces.
  - **CPP05-06** : Exceptions, casts.
  - **CPP07-09** : Templates, conteneurs STL (Standard Template Library).

---

## Les Projets Finaux

Ces projets de grande envergure combinent de nombreuses technologies et demandent une excellente organisation en groupe.

### `Inception`
![Docker](https://img.shields.io/badge/Tech-Docker_&_Nginx-blue.svg?style=for-the-badge&logo=docker)

- **Description** : Mettre en place une infrastructure multi-conteneurs (Nginx, WordPress, MariaDB) en utilisant `docker-compose`. Le but est de comprendre la conteneurisation et l'orchestration.
- **Compétences acquises** : Docker, Dockerfile, `docker-compose`, administration système, réseaux Docker, Nginx, bases de données SQL.

### `ft_irc`
![CPP](https://img.shields.io/badge/Language-C++-purple.svg?style=flat-square) ![Network](https://img.shields.io/badge/Tech-Networking-green.svg?style=flat-square)

- **Description** : Créer un serveur IRC (Internet Relay Chat) en C++. Le serveur doit être capable de gérer plusieurs clients simultanément et d'implémenter les commandes de base d'IRC.
- **Compétences acquises** : Programmation réseau (sockets, TCP/IP), gestion de multiples clients (select/poll), programmation orientée objet en C++.

### `ft_transcendence`
![FullStack](https://img.shields.io/badge/Tech-Full_Stack-orange.svg?style=for-the-badge&logo=typescript&logoColor=white) ![NestJS](https://img.shields.io/badge/NestJS-E0234E?style=for-the-badge&logo=nestjs&logoColor=white) ![React](https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB)

- **Description** : Le projet final du cursus. Développer une plateforme web complète pour jouer au jeu Pong en ligne et en temps réel, incluant un système de chat, d'amis, d'authentification (via OAuth2) et un matchmaking.
- **Compétences acquises** :
  - **Backend** : NestJS (Node.js), TypeScript, WebSockets, API REST, base de données (PostgreSQL), authentification (JWT, OAuth2).
  - **Frontend** : React/Vue/Angular, gestion d'état, communication avec une API.
  - **DevOps** : Dockerisation de l'ensemble de l'application.
  - **Gestion de projet** : Travail en équipe, Git, méthodologie Agile.

---

### Auteur

- **[Votre Nom]**
- **Login 42** : `votre-login`
- **GitHub** : `[@votre-github](https://github.com/votre-github)`
- **LinkedIn** : `[Votre Profil](https://www.linkedin.com/in/votre-profil/)`
