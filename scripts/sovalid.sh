#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

echo -e "${bleu}"
echo -e "███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗"
echo -e "██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝"
echo -e "███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
echo -e "╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║"
echo -e "███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
echo -e "╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "
echo -e "${neutre}"

make 2>/dev/null >/dev/null              # make et stdout et stderr redirigé vers null cad empeche l'affichage
cd maps/valid                            # on se déplace dans le fichier des maps non valides
echo "ARG=(" >>../../maps.sh             # on creer le fichier maps.sh qui sert de liste d'arguments (ARG)
ls | sed 's/^/"/;s/$/"/' >>../../maps.sh # on le remplis avec la list du dossier et ajoute des double quotes aux extremités avec sed
echo ")" >>../../maps.sh                 # on ferme la parenthèse de la liste d'argument
cd ../..                                 # on revient a la racine
source maps.sh                           # on source le fichier crée plus haut qui contient en ARG tous les noms des maps

for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
	echo -e "${bleu}-----------------------------------------------------------${neutre}"
	echo -e "        ${vert}$i${neutre}" # nom de l'argument (map)

	valgrind --track-fds=yes --leak-check=full ./so_long ./maps/valid/$i 2>tmp >/dev/null # on copie stderr (2) vers un fichier temporaire (tmp) et stdout vers null
	error=$(cat tmp | grep "segmentation fault" | wc -l)                                  # on recupère le resultat de grep error sur tmp dans une variable : error
	errjump=$(cat tmp | grep "Conditional jump" | wc -l)                                  # on recupère le resultat de grep error sur tmp dans une variable : error
	leaks=$(cat tmp | grep "no leaks are possible" | wc -l)
	fdclose=$(cat tmp | grep "FILE DESCRIPTOR" | awk '{gsub(/\(/, "", $6); print $6}')
	fdopen=$(cat tmp | grep "FILE DESCRIPTOR" | awk '{print $4}')

	if [ $fdopen -ne $fdclose ]; then
		success=${rouge}
	else
		success=${vert}
	fi

	printf ${bleu}"   Error : "
	if [ $error -eq 1 ] || [ $errjump -eq 1 ]; then # si grep égale 1 alors ok
		printf ${rouge}"[KO]"${neutre}
	else
		printf ${vert}"[OK]"${neutre}
	fi

	printf ${bleu}"   Leaks : "
	if [ $leaks -eq 1 ]; then # si grep égale 1 alors ok
		printf ${vert}"[OK]"${neutre}
	else
		printf ${rouge}"[KO]"${neutre}
	fi

	printf ${bleu}"   FDs : "
	printf ${success}"$fdclose/$fdopen${neutre}\n"
	echo -e "${bleu}-----------------------------------------------------------${neutre}"
	echo ""
	rm tmp

done
rm maps.sh # on efface le fichier maps.sh
make fclean >/dev/null
