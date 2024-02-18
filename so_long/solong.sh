#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make 2>/dev/null >/dev/null
cd maps
cd invalid
echo "ARG=(" >>../../maps.sh
ls | sed 's/^/"/;s/$/"/' >>../../maps.sh
echo ")" >>../../maps.sh
cd ../..

source maps.sh
if [ -z "$1" ]; then # [ -n "$1" ] : le contraire
	echo -e "${bleu}-------------------------------------------"
	echo -e "                var is unset"
	echo -e "-------------------------------------------${neutre}"
else
	for i in "${ARG[@]}"; do
		if [ $1 -eq 1 ]; then
			echo -e "${bleu}With arg : $i${neutre}"
			./so_long ./maps/invalid/$i
		elif [ $1 -eq 2 ]; then
			./so_long ./maps/invalid/$i 2>&1 >/dev/null | grep "Error" | wc -l >tmp
			grep=$(cat tmp)
			if [ $grep -eq 1 ]; then
				echo -e "${vert}[OK]${neutre}"
			else
				echo -e "${rouge}[KO]${neutre}"
			fi
			rm tmp
		else
			echo -e "${bleu}-------------------------------------------"
			echo -e "Taper 1 pour messages erreur ou 2 pour test rapide"
			echo -e "-------------------------------------------${neutre}"
			break
		fi
	done
fi

rm maps.sh
make fclean >/dev/null
