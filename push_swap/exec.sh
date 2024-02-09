#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make >/dev/null

ARG=(
	"4 67 3 087 23"
	"45 35f 76 99"
	"56 08 2147483648 43"
	"56 08 2147483647 43"
	"56 08 +2147483647 43"
	"56 98 809 34 45 56"
	"56 08 -2147483649 43"
	"56 08 -2147483648 43"
	"56 08 -2247483648 43"
)

for i in "${ARG[@]}"; do
	echo -e "${bleu}With arg : $i${neutre}"
	./push_swap $i
done

make fclean >/dev/null
