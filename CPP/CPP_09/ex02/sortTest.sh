#!/bin/bash

# Couleurs
rouge='\e[1;31m'
jaune='\e[1;33m'
bleu='\e[1;34m'
violet='\e[1;35m'
vert='\e[1;32m'
neutre='\e[0;m'

echo -e "${bleu}"
echo -e "		╔═╗┌┬┐┌─┐┬─┐┌─┐┌─┐╔╦╗┌─┐"
echo -e "		╠═╝│││├┤ ├┬┘│ ┬├┤ ║║║├┤ "
echo -e "		╩  ┴ ┴└─┘┴└─└─┘└─┘╩ ╩└─┘"
echo -e "${neutre}"


echo -e "${bleu} ---------------------- ${vert}SELECT TEST ${bleu}----------------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} --------------- ${vert}Display : Type D/d ${bleu}-----------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} ----------------- ${vert}Test : Type T/t ${bleu}-----------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${bleu} -------------------- ${vert}All : Type A/a ${bleu}---------------------"
echo -e "${bleu}-----------------------------------------------------------${neutre}"
echo -e "${vert}"
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
	echo "pas de list"
	echo "ARG=(" >> list
	echo ")" >> list
	for i in {1..33}; do
		bash getRndom.sh "$i" 1000
		done
	bash getRndom.sh 100 10000
	bash getRndom.sh 500 10000
	bash getRndom.sh 1000 10000
	bash getRndom.sh 3000 10000
fi
source list
echo -e "${bleu}-----------------------------------------------------------${neutre}"

if [ $mode -eq 1 ]; then
	for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
		size=$(echo "$i" | wc -w)
		echo -e "     ${jaune}List Size : $size ${neutre}"

		valgrind --track-fds=yes --leak-check=full ./PmergeMe $i 2>/dev/null # on copie stderr (2) vers un fichier temporaire (tmp) et stdout vers null
	done
fi

if [ $mode -eq 2 ]; then
	for i in "${ARG[@]}"; do # on parcours la liste d'argument ARG
		size=$(echo "$i" | wc -w)
		echo -e "     ${jaune}List Size : $size ${neutre}"
		echo -e "        ${vert}$i${neutre}" # nom de l'argument (map)

		valgrind --track-fds=yes --leak-check=full ./PmergeMe $i 2>errorFile >tmp # on copie stderr (2) vers un fichier temporaire (tmp) et stdout vers null
		error=$(cat errorFile | grep "segmentation fault" | wc -l)                      # on recupère le resultat de grep error sur tmp dans une variable : error
		errjump=$(cat errorFile | grep "Conditional jump" | wc -l)                      # on recupère le resultat de grep error sur tmp dans une variable : error
		leaks=$(cat errorFile | grep "no leaks are possible" | wc -l)
		fdclose=$(cat errorFile | grep "FILE DESCRIPTOR" | awk '{gsub(/\(/, "", $6); print $6}')
		fdopen=$(cat errorFile | grep "FILE DESCRIPTOR" | awk '{print $4}')

		if [ $fdopen -ne $fdclose ]; then
			success=${rouge}
		else
			success=${vert}
		fi

		printf ${bleu}"   Error : "
		if [ $error -eq 1 ] || [ $errjump -eq 1 ]; then # si grep égale 1 alors ok
			printf ${rouge}"[KO]"${neutre}
		else
			printf ${vert}"[OK]"${neutre}
		fi

		printf ${bleu}"   Leaks : "
		if [ $leaks -eq 1 ]; then # si grep égale 1 alors ok
			printf ${vert}"[OK]"${neutre}
		else
			printf ${rouge}"[KO]"${neutre}
		fi

		printf ${bleu}"   FDs : "
		printf ${success}"$fdclose/$fdopen${neutre}\n"

		# 🔹 Récupération du nombre d'éléments attendu (x)
		x=$(grep -oP 'Time to process a range of \K\d+' tmp | head -n 1)

		# 🔹 Extraction des nombres de la ligne "After: "
		after_list=$(grep "After:" tmp | cut -d':' -f2- | tr -d '"' | xargs)

		# 🔹 Vérification du nombre d'éléments
		actual_count=$(echo "$after_list" | wc -w)

		if [ "$actual_count" -eq "$x" ]; then
			printf ${bleu}"   Count : "${vert}"[OK]"${neutre}
		else
			printf ${bleu}"   Count : "${rouge}"[KO] ($actual_count/$x)"${neutre}
		fi

		# Vérification si la liste contient les memes nombres
		sorted1=$(echo $after_list | tr ' ' '\n' | sort | tr '\n' ' ')
		sorted2=$(echo $i | tr ' ' '\n' | sort | tr '\n' ' ')
		if [ "$sorted1" = "$sorted2" ]; then
			echo "identiques"
			else
			echo "pas pareil"
		fi
		# 🔹 Vérification si la liste est triée
		is_sorted=1
		prev=-999999999 # Petit nombre pour comparaison

		for num in $after_list; do
			if [ "$num" -lt "$prev" ]; then
				is_sorted=0
				break
			fi
			prev=$num
		done

		printf ${bleu}"   Sorted : "
		if [ "$is_sorted" -eq 1 ]; then
			printf ${vert}"[OK]\n"${neutre}
		else
			printf ${rouge}"[KO]\n"${neutre}
		fi

		echo -e "${bleu}-----------------------------------------------------------${neutre}"
		echo ""
		rm tmp
		rm errorFile
	done
fi
rm list
make fclean >/dev/null
