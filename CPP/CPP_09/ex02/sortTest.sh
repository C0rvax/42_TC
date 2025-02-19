#!/bin/bash

# Couleurs
RED='\e[1;31m'
YELLOW='\e[1;33m'
BLUE='\e[1;34m'
VIOLET='\e[1;35m'
GREEN='\e[1;32m'
NEUTRAL='\e[0;m'

echo -e "${BLUE}"
echo -e "		╔═╗┌┬┐┌─┐┬─┐┌─┐┌─┐╔╦╗┌─┐"
echo -e "		╠═╝│││├┤ ├┬┘│ ┬├┤ ║║║├┤ "
echo -e "		╩  ┴ ┴└─┘┴└─└─┘└─┘╩ ╩└─┘"
echo -e "${NEUTRAL}"

echo -e "${BLUE} ---------------------- ${GREEN}SELECT TEST ${BLUE}----------------------"
echo -e "${BLUE}-----------------------------------------------------------${NEUTRAL}"
echo -e "${BLUE} --------------- ${GREEN}Display : Type D/d ${BLUE}-----------------"
echo -e "${BLUE}-----------------------------------------------------------${NEUTRAL}"
echo -e "${BLUE} ----------------- ${GREEN}Test : Type T/t ${BLUE}-----------------"
echo -e "${BLUE}-----------------------------------------------------------${NEUTRAL}"
echo -e "${BLUE} -------------------- ${GREEN}All : Type A/a ${BLUE}---------------------"
echo -e "${BLUE}-----------------------------------------------------------${NEUTRAL}"
echo -e "${GREEN}"
read -p "                [d/t/a]" rep
case $rep in
D)
	mode=1
	;;
d)
	mode=1
	;;
T)
	mode=2
	;;
t)
	mode=2
	;;
A)
	mode=3
	;;
a)
	mode=3
	;;
*)
	mode=4
	;;
esac
make 2>/dev/null >/dev/null
if [[ ! -e "list" ]]; then
	echo "ARG=(" >>list
	echo ")" >>list
	for i in {1..33}; do
		bash getRndom.sh "$i" 1000
	done
	bash getRndom.sh 100 10000
	bash getRndom.sh 200 10000
	bash getRndom.sh 500 10000
	bash getRndom.sh 1000 10000
	bash getRndom.sh 3000 10000
fi
source list
echo -e "${BLUE}-----------------------------------------------------------${NEUTRAL}"

if [ $mode -eq 1 ] || [ $mode -eq 3 ]; then
	for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
		size=$(echo "$i" | wc -w)
		echo -e "     ${YELLOW}List Size : $size ${NEUTRAL}"

		valgrind --track-fds=yes --leak-check=full ./PmergeMe $i 2>/dev/null
	done
fi

if [ $mode -eq 2 ] || [ $mode -eq 3 ]; then
	for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
		size=$(echo "$i" | wc -w)
		echo -e "     ${YELLOW}List Size : $size ${NEUTRAL}"
		#echo -e "        ${GREEN}$i${NEUTRAL}" # nom de l'argument (map)

		valgrind --track-fds=yes --leak-check=full ./PmergeMe $i 2>errorFile >tmp
		error=$(cat errorFile | grep "segmentation fault" | wc -l)
		errjump=$(cat errorFile | grep "Conditional jump" | wc -l)
		leaks=$(cat errorFile | grep "no leaks are possible" | wc -l)
		fdclose=$(cat errorFile | grep "FILE DESCRIPTOR" | awk '{gsub(/\(/, "", $6); print $6}')
		fdopen=$(cat errorFile | grep "FILE DESCRIPTOR" | awk '{print $4}')

		if [ $fdopen -ne $fdclose ]; then
			success=${RED}
		else
			success=${GREEN}
		fi

		printf ${BLUE}"   Error : "
		if [ $error -eq 1 ] || [ $errjump -eq 1 ]; then # si grep égale 1 alors ok
			printf ${RED}"[KO]"${NEUTRAL}
		else
			printf ${GREEN}"[OK]"${NEUTRAL}
		fi

		printf ${BLUE}"   Leaks : "
		if [ $leaks -eq 1 ]; then # si grep égale 1 alors ok
			printf ${GREEN}"[OK]"${NEUTRAL}
		else
			printf ${RED}"[KO]"${NEUTRAL}
		fi

		printf ${BLUE}"   FDs : "
		printf ${success}"$fdclose/$fdopen${NEUTRAL}\n"

		# 🔹 Récupération du nombre d'éléments attendu (x)
		x=$(grep -oP 'Time to process a range of \K\d+' tmp | head -n 1)

		# 🔹 Extraction des nombres de la ligne "After: "
		after_list=$(grep "After:" tmp | cut -d':' -f2- | tr -d '"' | xargs)

		# 🔹 Vérification du nombre d'éléments
		actual_count=$(echo "$after_list" | wc -w)

		if [ "$actual_count" -eq "$x" ]; then
			printf ${BLUE}"   Count : "${GREEN}"[OK]"${NEUTRAL}
		else
			printf ${BLUE}"   Count : "${RED}"[KO] ($actual_count/$x)"${NEUTRAL}
		fi

		# Vérification si la liste contient les memes nombres
		sorted1=$(echo $after_list | tr ' ' '\n' | sort | tr '\n' ' ')
		sorted2=$(echo $i | tr ' ' '\n' | sort | tr '\n' ' ')
		if [ "$sorted1" = "$sorted2" ]; then
			printf ${BLUE}"   Same list : "${GREEN}"[OK]"${NEUTRAL}
		else
			printf ${BLUE}"   Same list : "${RED}"[KO]"${NEUTRAL}
		fi

		# 🔹 Vérification si la liste est triée
		is_sorted=1
		prev=-1 # Petit nombre pour comparaison

		for num in $after_list; do
			if [ "$num" -lt "$prev" ]; then
				is_sorted=0
				break
			fi
			prev=$num
		done

		printf ${BLUE}"   Sorted : "
		if [ "$is_sorted" -eq 1 ]; then
			printf ${GREEN}"[OK]\n"${NEUTRAL}
		else
			printf ${RED}"[KO]\n"${NEUTRAL}
		fi

		echo -e "${BLUE}-----------------------------------------------------------${NEUTRAL}"
		echo ""
		rm tmp
		rm errorFile
	done
fi
rm list
make fclean >/dev/null
