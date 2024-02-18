#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

make >/dev/null
cd push_swap_visualizer/build/
./bin/visualizer
cd ../..

make fclean >/dev/null
