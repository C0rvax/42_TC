#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make >/dev/null
cd push_swap_tester
make >/dev/null
check=(../checker)
./complexity $1 $2 $3

make fclean >/dev/null
cd ..
make fclean >/dev/null
