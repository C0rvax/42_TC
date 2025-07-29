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
6.  [Le Projet Final - ft_transcendence](#le-projet-final---ft_transcendence)

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

### `ft_irc`
![CPP](https://img.shields.io/badge/Language-C++-purple.svg?style=flat-square) ![Network](https://img.shields.io/badge/Tech-Networking-green.svg?style=flat-square)

- **Description** : Créer un serveur IRC (Internet Relay Chat) en C++. Le serveur doit être capable de gérer plusieurs clients simultanément et d'implémenter les commandes de base d'IRC.
- **Compétences acquises** : Programmation réseau (sockets, TCP/IP), gestion de multiples clients (select/poll), programmation orientée objet en C++.

### `Inception`
![Docker](https://img.shields.io/badge/Tech-Docker_&_Nginx-blue.svg?style=for-the-badge&logo=docker)

- **Description** : Mettre en place une infrastructure multi-conteneurs (Nginx, WordPress, MariaDB) en utilisant `docker-compose`. Le but est de comprendre la conteneurisation et l'orchestration.
- **Compétences acquises** : Docker, Dockerfile, `docker-compose`, administration système, réseaux Docker, Nginx, bases de données SQL.

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

## Le Projet Final - ft_transcendence

![FullStack](https://img.shields.io/badge/Tech-Full_Stack-orange.svg?style=for-the-badge&logo=typescript&logoColor=white) ![Fastify](https://img.shields.io/badge/Fastify-000000?style=for-the-badge&logo=fastify&logoColor=white) ![TailwindCSS](https://img.shields.io/badge/Tailwind_CSS-38B2AC?style=for-the-badge&logo=tailwind-css&logoColor=white) ![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)

`ft_transcendence` est le projet final du cursus de l'école 42, une épreuve d'endurance qui synthétise l'ensemble des compétences acquises. L'objectif est de créer une plateforme web complète pour jouer à **Pong en temps réel et en multijoueur**.

Le projet est modulaire : il part d'une base obligatoire et s'enrichit par l'implémentation de modules aux contraintes technologiques imposées.

### Architecture et Technologies

- **Backend** : **Node.js** avec le framework **Fastify**, architecturé en **microservices** pour la scalabilité et la maintenabilité.
- **Frontend** : Application **Single Page (SPA)** développée en **TypeScript** et stylisée avec **Tailwind CSS**.
- **Base de données** : **SQLite** pour la persistance des données.
- **Infrastructure & DevOps** : Le projet est entièrement conteneurisé avec **Docker** et `docker-compose`. Le monitoring est assuré par la stack **Prometheus & Grafana**.
- **Communication temps réel** : **WebSockets** pour le jeu en direct et le chat.

### Modules Implémentés

J'ai réalisé une sélection de modules pour construire une application robuste et complète :

- **Web (Major & Minors)** :
  - `Framework Backend` : Utilisation de **Fastify (Node.js)** pour une API performante.
  - `Framework Frontend` : Interface moderne avec **TypeScript & Tailwind CSS**.
  - `Database` : Intégration de **SQLite** pour la gestion des données utilisateurs.

- **User Management (Majors)** :
  - `Standard User Management` : Système complet de gestion des utilisateurs : inscription, connexion, profil personnalisable avec avatar, liste d'amis avec statut en direct, et historique des matchs.
  - `Remote Authentication` : Implémentation de l'authentification via un service tiers (**Google Sign-in** - OAuth2).

- **Gameplay & User Experience (Major)** :
  - `Remote Players` : Le cœur du projet, permettant à deux joueurs de s'affronter à distance en temps réel via le réseau.

- **Cybersecurity (Major)** :
  - `2FA & JWT` : Sécurisation de l'application avec des **JSON Web Tokens (JWT)** pour les sessions et une authentification à deux facteurs (**2FA**) pour les comptes utilisateurs.

- **DevOps (Major & Minor)** :
  - `Designing the Backend as Microservices` : Architecture du backend en services indépendants (ex: service utilisateur, service de jeu) pour une meilleure résilience et scalabilité.
  - `Monitoring System` : Mise en place de **Prometheus** pour la collecte de métriques et de **Grafana** pour la création de dashboards de visualisation.

- **Accessibility (Minor)** :
  - `Multiple Language Support` : Internationalisation de l'interface pour la rendre accessible en plusieurs langues.

- **AI-Algo (Minor)** :
  - `User and Game Stats Dashboards` : Création de tableaux de bord pour que les utilisateurs puissent visualiser leurs statistiques de jeu (victoires, défaites, etc.).

### Compétences Clés Démontrées

- **Développement Backend** : Conception d'API RESTful, architecture microservices, programmation asynchrone (Node.js), gestion de bases de données SQL.
- **Développement Frontend** : Création d'interfaces utilisateur réactives et dynamiques (SPA), gestion d'état, communication avec une API.
- **DevOps & Infrastructure** : Conteneurisation (Docker), orchestration simple (docker-compose), mise en place de monitoring.
- **Réseau & Temps Réel** : Utilisation des WebSockets pour une faible latence.
- **Cybersécurité** : Implémentation de standards d'authentification modernes (OAuth2, JWT, 2FA).
- **Gestion de projet** : Conception d'une application complexe, décomposition en modules, respect de contraintes techniques fortes.

---

### Auteur

- **Arthur Duvillaret**
- **Login 42** : `aduvilla`
- **GitHub** : [@C0rvax](https://github.com/C0rvax)
- **LinkedIn** : [Arthur Duvillaret](https://www.linkedin.com/in/arthur-duvillaret-427912377/)
