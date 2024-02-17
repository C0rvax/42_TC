#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make >/dev/null
cd maps
cd invalid
echo "ARG=(" >>../../maps.sh
ls | sed 's/^/"/;s/$/"/' >>../../maps.sh
echo ")" >>../../maps.sh
cd ../..

source maps.sh
for i in "${ARG[@]}"; do
	echo -e "${bleu}With arg : $i${neutre}"
	./so_long ./maps/invalid/$i
	#	valgrind ./push_swap $i
	#	valgrind ./push_swap $i | ./checker_linux $i
	#	./push_swap $i | ./checker_linux $i
done

rm maps.sh
make fclean >/dev/null
