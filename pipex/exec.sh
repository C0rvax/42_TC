#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

function check_outfile {
	diff --brief outfile outfile2 >/dev/null
	comp_value=$?

	if [ $comp_value -eq 1 ]; then
		echo -e "${rouge}[KO]${neutre}"
	else
		echo -e "${vert}[OK]${neutre}"
	fi
	rm outfile outfile2
}

make >/dev/null

echo -e "${bleu} TEST : grep la | wc -w ${neutre}"
valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "wc -w" outfile
valgrind --leak-check=full --trace-children=yes grep 'la' <infile | wc -w >outfile2
check_outfile

echo -e "${bleu} TEST : grep la | grep - ${neutre}"
valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "grep -" outfile
valgrind --leak-check=full --trace-children=yes grep 'la' <infile | grep '-' >outfile2
check_outfile

echo -e "${bleu} TEST : grep la | wc -w | wc -w ${neutre}"
valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "grep -" "wc -w" outfile
valgrind --leak-check=full --trace-children=yes grep 'la' <infile | grep '-' | wc -w >outfile2
check_outfile

echo -e "${bleu} TEST : grep la | cat | wc -w ${neutre}"
valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "cat" "wc -w" outfile
valgrind --leak-check=full --trace-children=yes grep 'la' <infile | cat | wc -w >outfile2
check_outfile

echo -e "${bleu} TEST : grep la | cat | wc -w ${neutre}"
./pipex infile "grep la" "cat" "wc -w" outfile
grep 'la' <infile | cat | wc -w >outfile2
check_outfile
make fclean >/dev/null
