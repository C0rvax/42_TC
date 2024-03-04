#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

echo -e "${bleu} ---------------------- ${vert}SELECT TEST ${bleu}----------------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} --------------- ${vert}Test Général : Type G/g ${bleu}-----------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} ----------------- ${vert}Mass Tests : Type M/m ${bleu}-----------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} ----------------- ${vert}Visualizer : Type V/v ${bleu}-----------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} -------------------- ${vert}All : Type A/a ${bleu}---------------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} ------------------- ${vert}Bonus : Type B/b ${bleu}--------------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${vert}"
read -p "                [M/g/V/b/A]" rep
echo -e "${bleu}"
case $rep in
M)
	mode=1
	;;
m)
	mode=1
	;;
V)
	mode=2
	;;
v)
	mode=2
	;;
G)
	mode=3
	;;
g)
	mode=3
	;;
A)
	mode=4
	;;
a)
	mode=4
	;;
B)
	mode=6
	;;
b)
	mode=6
	;;
*)
	mode=5
	;;
esac

if [ $mode -eq 1 ] || [ $mode -eq 4 ]; then
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

	echo -e "${bleu} TEST : grep la | wc -w PIPEX"
	valgrind --leak-check=full --trace-children=yes --track-fds=yes ./pipex infile "grep la" "wc -w" outfile
	echo -e "${jaune} TEST : grep la | wc -w BASH"
	valgrind --leak-check=full --trace-children=yes --track-fds=yes grep 'la' <infile | wc -w >outfile2
	check_outfile
	echo -e "------------------------------------------------------------------------"

	echo -e "${bleu} TEST : grep la | grep - PIPEX"
	valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "grep -" outfile
	echo -e "${jaune} TEST : grep la | grep - BASH"
	valgrind --leak-check=full --trace-children=yes grep 'la' <infile | grep '-' >outfile2
	check_outfile
	echo -e "------------------------------------------------------------------------"

	echo -e "${bleu} TEST : grep la | wc -w | wc -w PIPEX"
	valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "grep -" "wc -w" outfile
	echo -e "${jaune} TEST : grep la | wc -w | wc -w BASH"
	valgrind --leak-check=full --trace-children=yes grep 'la' <infile | grep '-' | wc -w >outfile2
	check_outfile
	echo -e "------------------------------------------------------------------------"

	echo -e "${bleu} TEST : grep la | cat | wc -w PIPEX"
	valgrind --leak-check=full --trace-children=yes ./pipex infile "grep la" "cat" "wc -w" outfile
	echo -e "${jaune} TEST : grep la | cat | wc -w BASH"
	valgrind --leak-check=full --trace-children=yes grep 'la' <infile | cat | wc -w >outfile2
	check_outfile
	echo -e "------------------------------------------------------------------------"

	echo -e "${bleu} TEST : grep la | cat | wc -w ${neutre}"
	./pipex infile "grep la" "cat" "wc -w" outfile
	grep 'la' <infile | cat | wc -w >outfile2
	check_outfile
	make fclean >/dev/null
fi
