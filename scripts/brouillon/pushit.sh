#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'
DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

echo -e "${bleu} ----------- ${vert}SELECT MODE ${bleu}-----------"
echo -e "${bleu} -----------------------------------"
echo -e "${bleu} ---- ${vert}Tests em Mass : Type M/m ${bleu}-----"
echo -e "${bleu} -----------------------------------"
echo -e "${bleu} ----- ${vert}Test Général : Type G/g ${bleu}-----"
echo -e "${bleu} -----------------------------------"
echo -e "${bleu} ------ ${vert}Visualizer : Type V/v ${bleu}------"
echo -e "${bleu} -----------------------------------"
echo -e "${vert}"
read -p "                [m/g/v]" rep
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
*)
	mode=4
	;;
esac

if [ $mode -eq 1 ]; then

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

elif [ $mode -eq 2 ]; then

	make >/dev/null
	cd push_swap_visualizer/build/
	./bin/visualizer
	cd ../..

	make fclean >/dev/null
elif [ $mode -eq 3 ]; then

	make >/dev/null
	rm -rf traces.txt
	rm -rf 0

	FILE=$PWD/push_swap
	FICHERO=test_check.txt

	ARG=(
		"a"
		"111a11"
		"hello world"
		"0 0"
		"-01 -001"
		"111-1 2 -3"
		"-3 -2 -2"
		"\n"
		"-2147483649"
		"-2147483650"
		"2147483648"
		"8 008 12"
		"10 -1 -2 -3 -4 -5 -6 90 99 10"
		"1 +1 -1"
		"3333-3333 1 4"
		"111a111 -4 3"
		"111111 -4 3 03"
		"2147483649"
		"2147483647+1"
		"0 1 2 3 4 5 0"
		"3 +3"
		"3+3"
		"42 42"
		"42 -42 -42 "
		"4222-4222"
		"99999999999999999999999999"
		"-99999999999999999999999999"
		"0 -0 1 -1"
		"0 +0 1 -1"
		"111+111 -4 3"
		"-"
		"+"
		"--123 1 321"
		"++123 1 321"
		"0000000000000000000000009 000000000000000000000009"
		"00000001 1 9 3"
		"00000003 003 9 1"
		"--21345"
		"1 01"
		"-000 -0000"
		"-00042 -000042"
	)
	printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR}
	printf ${BLUE}"\n\t\t\tCONTROL ERRORS\t\n"${DEF_COLOR}
	printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}
	n=1
	for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
		./push_swap $i >/dev/null 2>test_check.txt
		if [ -s "$FICHERO" ]; then
			while IFS= read -r line; do
				if [[ $line == "Error" ]]; then
					printf "${GREEN}$n.[OK] ${DEF_COLOR}\n"
				else
					printf "${RED}$n.[KO] ${DEF_COLOR}\n"
					break
				fi
			done <test_check.txt
		else
			printf "${RED}$n.[KO] ${DEF_COLOR}\n"
		fi
		((n = n + 1))
		rm -rf test_check.txt
	done
	./push_swap "" >/dev/null 2>test_check.txt
	if [ -s "$FICHERO" ]; then
		while IFS= read -r line; do
			if [[ $line == "Error" ]]; then
				printf "${GREEN}$n.[OK] ${DEF_COLOR}\n"
			else
				printf "${RED}$n.[KO] ${DEF_COLOR}\n"
				break
			fi
		done <test_check.txt
	else
		printf "${RED}$n.[KO] ${DEF_COLOR}\n"
	fi
	((n = n + 1))
	rm -rf test_check.txt
	rm -rf 0
	ARG2=(
		"2 1"
		"1 3 2"
		"2 3 1"
		"2 1 3"
		"3 1 2"
		"3 2 1"
	)

	printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR}
	printf ${BLUE}"\n\t\t\tBasic input\t\t\n"${DEF_COLOR}
	printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}

	for i in "${ARG2[@]}"; do # on parcours la liste d'argument ARG
		N=$(./push_swap $i | wc -l)
		if [ $N -lt 4 ]; then
			printf "${GREEN}$n.[OK] ${DEF_COLOR}"
		else
			printf "${RED}$n.[KO]${DEF_COLOR}"
			printf "${WHITE} TEST: "
			echo -n "$ARG "
		fi
		((n = n + 1))
		S=$(./push_swap $i | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN}$n.[OK] ${DEF_COLOR}"
		else
			printf "${RED}$n.[KO]${DEF_COLOR}"
		fi
		rm -rf test_check.txt
		rm -rf 0
		((n = n + 1))
	done
	ARG3=(
		"1 2 4 3"
		"1 3 2 4"
		"1 3 4 2"
		"1 4 3 2"
		"1 4 2 3"
		"2 3 4 1"
		"2 4 3 1"
		"2 1 4 3"
		"2 1 3 4"
		"2 3 1 4"
		"2 4 1 3"
		"3 4 1 2"
		"3 4 2 1"
		"3 2 1 4"
		"3 1 2 4"
		"3 1 2 4"
		"3 2 4 1"
		"3 1 4 2"
		"4 1 2 3"
		"4 1 3 2"
		"4 2 1 3"
		"4 2 3 1"
		"4 3 1 2"
		"4 3 2 1"
	)

	for i in "${ARG3[@]}"; do # on parcours la liste d'argument ARG
		N=$(./push_swap $i | wc -l)
		if [ $N -lt 13 ]; then
			printf "${GREEN}$n.[OK] ${DEF_COLOR}"
		else
			printf "${RED}$n.[KO]${DEF_COLOR}"
			printf "${WHITE} TEST: "
			echo -n "$ARG "
		fi

		((n = n + 1))
		S=$(./push_swap $i | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN}$n.[OK] ${DEF_COLOR}"
		else
			printf "${RED}$n.[KO]${DEF_COLOR}"
		fi
		((n = n + 1))
	done

	ARG4=(
		ARG="1 2 3 5 4"
		ARG="1 2 4 3 5"
		ARG="1 2 4 5 3"
		ARG="1 2 5 3 4"
		ARG="1 2 5 4 3"
		ARG="1 3 2 4 5"
		ARG="1 3 2 5 4"
		ARG="1 3 4 2 5"
		ARG="1 3 4 5 2"
		ARG="1 3 5 2 4"
		ARG="1 3 5 4 2"
		ARG="1 4 2 3 5"
		ARG="1 4 2 5 3"
		ARG="1 4 3 2 5"
		ARG="1 4 3 5 2"
		ARG="1 4 5 2 3"
		ARG="1 4 5 3 2"
		ARG="1 5 2 3 4"
		ARG="1 5 2 4 3"
		ARG="1 5 3 2 4"
		ARG="1 5 3 4 2"
		ARG="1 5 3 4 2"
		ARG="1 5 4 2 3"
		ARG="1 5 4 3 2"
		ARG="2 1 3 4 5"
		ARG="2 1 3 5 4"
		ARG="2 1 4 3 5"
		ARG="2 1 4 5 3"
		ARG="2 1 5 3 4"
		ARG="2 1 5 4 3"
	)
	printf ${BLUE}"\n\n-------------------------------------------------------------\n\n"${DEF_COLOR}
	printf ${BLUE}"\n\t\t\tSize 5\t\t\n"${DEF_COLOR}
	printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}

	for i in "${ARG4[@]}"; do # on parcours la liste d'argument ARG
		N=$(./push_swap $i | wc -l)
		if [ $N -lt 13 ]; then
			printf "${GREEN}$n.[OK] ${DEF_COLOR}"
		else
			printf "${RED}$n.[KO]${DEF_COLOR}"
			printf "${WHITE} TEST: "
			echo -n "$ARG "
		fi
		((n = n + 1))
		S=$(./push_swap $i | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN}$n.[OK] ${DEF_COLOR}"
		else
			printf "${RED}$n.[KO]${DEF_COLOR}"
		fi
		((n = n + 1))
	done
	make fclean >/dev/null
fi
