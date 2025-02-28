# Conda Cheat Sheet 🐍

## Introduction
[Conda](https://docs.conda.io/en/latest/) est un gestionnaire de paquets et d'environnements qui simplifie l'installation et la gestion des bibliothèques Python et de leurs dépendances.

---

## 📥 Installation de Conda

- **Installer Anaconda** (distribution complète) : [Télécharger Anaconda](https://www.anaconda.com/)
- **Installer Miniconda** (version légère) : [Télécharger Miniconda](https://docs.conda.io/en/latest/miniconda.html)

---

## 🔍 Vérification de l'installation
```sh
conda --version  # Vérifier la version de Conda
conda info       # Obtenir des informations sur Conda
```

---

## 🔄 Mise à jour de Conda
```sh
conda update -n base -c defaults conda  # Mettre à jour Conda lui-même
conda update conda                     # Mettre à jour Conda
conda update --all                      # Mettre à jour tous les paquets
```

---

## 📂 Gestion des environnements

### 🔹 Créer un nouvel environnement
```sh
conda create -n mon_env python=3.9  # Créer un environnement avec Python 3.9
conda create -n mon_env numpy pandas scikit-learn  # Avec des paquets spécifiques
```

### 🔹 Lister les environnements
```sh
conda env list  # Liste des environnements existants
conda info --envs  # Alternative pour lister les environnements
```

### 🔹 Activer/Désactiver un environnement
```sh
conda activate mon_env  # Activer un environnement
conda deactivate        # Désactiver l’environnement actif
```

### 🔹 Supprimer un environnement
```sh
conda remove -n mon_env --all  # Supprimer un environnement
```

---

## 📦 Gestion des paquets

### 🔹 Rechercher un paquet
```sh
conda search numpy  # Rechercher un paquet spécifique
```

### 🔹 Installer un paquet
```sh
conda install numpy pandas  # Installer plusieurs paquets
conda install -c conda-forge opencv  # Installer depuis un canal spécifique
```

### 🔹 Mettre à jour un paquet
```sh
conda update numpy  # Mettre à jour un paquet spécifique
```

### 🔹 Désinstaller un paquet
```sh
conda remove numpy  # Supprimer un paquet
```

### 🔹 Lister les paquets installés
```sh
conda list  # Liste tous les paquets installés
```

---

## 📄 Gestion des fichiers d’environnement

### 🔹 Exporter un environnement
```sh
conda env export > environment.yml  # Exporter un environnement vers un fichier
```

### 🔹 Créer un environnement depuis un fichier
```sh
conda env create -f environment.yml  # Reproduire un environnement à partir d’un fichier
```

---

## ⚡ Commandes avancées

### 🔹 Nettoyer Conda
```sh
conda clean --all  # Nettoyer les fichiers temporaires et caches inutiles
```

### 🔹 Cloner un environnement
```sh
conda create --name nouveau_env --clone mon_env  # Cloner un environnement existant
```

### 🔹 Lister les canaux Conda
```sh
conda config --show-sources  # Voir les canaux actuels
```

### 🔹 Ajouter un canal
```sh
conda config --add channels conda-forge  # Ajouter conda-forge aux sources
```

### 🔹 Supprimer un canal
```sh
conda config --remove channels conda-forge  # Supprimer un canal
```

---

## 🎯 Conclusion
Conda est un outil puissant pour gérer les environnements et les dépendances sans conflit. Il est indispensable pour les développeurs et les data scientists.

---

🔥 **Happy Coding!** 🚀
