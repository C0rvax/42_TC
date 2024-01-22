#!/bin/bash

ARGS=(
	'grep la'
	'wc -w'
)

ARG2=(
	'wc -w'
)
TEST= '< infile grep la | wc -w > outfile'

make

for ARG in "${ARGS[@]}"; do
	echo test de "${ARG}" "${ARG2}"
	valgrind --leak-check=full --trace-children=yes ./pipex infile "${ARG}" "${ARG2}" outfile2
	#valgrind --leak-check=full --trace-children=yes ${ARGB}
	echo outfile2
	cat outfile2
	#	< infile "${ARG}" | "${ARG2}" > outfile
	"${TEST}"
	valgrind --leak-check=full --trace-children=yes grep 'la' <infile | wc -w >outfile
	echo outfile
	cat outfile
done

make fclean
