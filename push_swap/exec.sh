#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make >/dev/null

ARG="4 67 3 087 23"

ERRC="45 35f 76 99"

ERRM="56 08 2147483648 43"

echo -e "${bleu}test 1 : Arg : $ARG${neutre}"
./push_swap $ARG

echo -e "${bleu}test 1 : Arg : $ERRC${neutre}"
./push_swap $ERRC

echo -e "${bleu}test 1 : Arg : $ERRM${neutre}"
./push_swap $ERRM

make fclean >/dev/null
