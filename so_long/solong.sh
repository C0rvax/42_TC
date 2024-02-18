#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make 2>/dev/null >/dev/null              # make et stdout et stderr redirigé vers null cad empeche l'affichage
cd maps/invalid                          # on se déplace dans le fichier des maps non valides
echo "ARG=(" >>../../maps.sh             # on creer le fichier maps.sh qui sert de liste d'arguments (ARG)
ls | sed 's/^/"/;s/$/"/' >>../../maps.sh # on le rempli avec la list du dossier et ajoute des double quotes aux extremités avec sed
echo ")" >>../../maps.sh
cd ../.. # on revient a la racine

source maps.sh # on source le fichier creer plus haut qui contient en ARG tous les noms des maps

if [ -z "$1" ]; then # si la chaine $1 (1er arg) est vide [ -n "$1" ] : le contraire
	echo -e "${rouge}-----------------------------------------------------------"
	echo -e "                var is unset"
	echo -e "-----------------------------------------------------------${neutre}"

else
	for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
		if [ $1 -eq 1 ]; then
			echo -e "        ${vert}$i${neutre}"
			./so_long ./maps/invalid/$i 2>&1 >/dev/null | grep ":"
			echo -e "${bleu}-----------------------------------------------------------${neutre}"

		elif [ $1 -eq 2 ]; then
			./so_long ./maps/invalid/$i 2>&1 >/dev/null | grep "Error" | wc -l >tmp # on écrit combien de ligne contient Error dans un fichier tmp
			grep=$(cat tmp)                                                         # on recupère le resultat de tmp dans une variable : grep
			if [ $grep -eq 1 ]; then                                                # si grep égale 1 alors ok
				echo -e "${vert}   Error [OK]${neutre}"
			else
				echo -e "${rouge}   Error [KO]${neutre}"
			fi
			rm tmp

		elif [ $1 -eq 3 ]; then
			valgrind --leak-check=full ./so_long ./maps/invalid/$i 2>&1 >/dev/null | grep "no leaks are possible" | wc -l >tmp
			grep=$(cat tmp)
			if [ $grep -eq 1 ]; then
				echo -e "${vert}   Leak [OK]${neutre}"
			else
				echo -e "${rouge}   Leak [KO]${neutre}"
			fi
			rm tmp

		else
			echo -e "${rouge}-----------------------------------------------------------"
			echo -e "Taper 1 pour messages erreur ou 2 pour test rapide"
			echo -e "----------------------------------------------------------${neutre}"
			break
		fi
	done
fi

rm maps.sh # on efface le fichier maps.sh
make fclean >/dev/null
