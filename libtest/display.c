#include "libtest.h"

void	name(char *s)
{
	printf(AINSI_COLOR_YELLOW	"\n               %s\n"	AINSI_COLOR_RESET, s);
}

void	display(int exo, int ok)
{
	printf("Test %i : ", exo);	
	if (ok == 1)
		printf(AINSI_COLOR_GREEN	"OK ! "	AINSI_COLOR_RESET);
	else
		printf(AINSI_COLOR_RED		"KO ! "	AINSI_COLOR_RESET);
}
