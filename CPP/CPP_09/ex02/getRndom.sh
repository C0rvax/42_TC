#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
	echo "Usage: $0 <list size> <max>"
	exit 1
fi
count=$1
#max=2147483647
declare -A numbers

if ! [[ "$count" =~ ^[0-9]+$ ]] || [ "$count" -lt 0 ]; then
	echo "Error : list size negative"
	exit 1
fi

while [ ${#numbers[@]} -lt $count ]; do
	num=$((RANDOM % ($2 + 1))) # Génère un nombre entre 1 et arg 2
	if [ "$num" -le "$2" ]; then
		numbers[$num]=1
	fi
done

new_line="\"${!numbers[@]}\""
sed -i "/)/i $new_line" list
