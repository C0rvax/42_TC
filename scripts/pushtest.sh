#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

# set best scores limits
lim3=3
lim5=12
lim100=700
lim500=5500

make >/dev/null
cd push_swap_tester
make >/dev/null

./complexity 3 500 $lim3
./complexity 5 500 $lim5
./complexity 100 500 $lim100
./complexity 500 100 $lim500

make fclean >/dev/null
cd ..
make fclean >/dev/null
