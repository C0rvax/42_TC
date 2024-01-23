#!/bin/bash

make

valgrind --leak-check=full --trace-children=yes ./pipex infile "${CMD1[i]}" "${CMD2[i]}" outfile2

valgrind --leak-check=full --trace-children=yes ./pipex infile "${CMD1[i]}" "${CMD2[i]}" outfile2

diff --brief <(sort file1) <(sort file2) >/dev/null
comp_value=$?

if [ $comp_value -eq 1 ]; then
	echo "do something because they're different"
else
	echo "do something because they're identical"
fi

make fclean
