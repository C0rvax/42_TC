#ifndef LIBTEST_H
# define LIBTEST_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define AINSI_COLOR_RED		"\x1b[31m"
#define AINSI_COLOR_GREEN	"\x1b[32m"
#define AINSI_COLOR_YELLOW	"\x1b[33m"
#define AINSI_COLOR_RESET	"\x1b[0m"

void	display(int exo, int ok);
void	name(char *s);

#endif
