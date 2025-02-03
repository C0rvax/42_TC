#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
	echo "Usage: $0 <list size> <max>"
	exit 1
fi
count=$1
max=$2
declare -A numbers

if ! [[ "$count" =~ ^[0-9]+$ ]] || [ "$count" -lt 0 ]; then
	echo "Error : list size negative"
	exit 1
fi

if ! [[ "$max" =~ ^[0-9]+$ ]] || [ "$max" -lt 0 ]; then
	echo "Error : max int negative"
	exit 1
fi

while [ ${#numbers[@]} -lt $count ]; do
	num=$((RANDOM % ($max + 1))) # Génère un nombre entre 1 et arg 2
	if [ "$num" -le "$max" ]; then
		numbers[$num]=1
	fi
done

if [[ ! -e "list" ]]; then
	echo "ARG=(" >>list
	echo ")" >>list
fi

new_line="\"${!numbers[@]}\""
sed -i "/)/i $new_line" list
