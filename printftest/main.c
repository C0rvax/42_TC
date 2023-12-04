#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    int i;
    char *nu = NULL;

    i = 0;
    i = ft_printf("FT  : Ca marche avec des int : %i et des dec : %d  ", 25, 450);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des int : %i et des dec : %d  ", 25, 450);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des char : %c et des str : %s  ", 'a', "hahaha");
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des char : %c et des str : %s  ", 'a', "hahaha");
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des pointeurs : %p  ", &i);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des pointeurs : %p  ", &i);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des pointeurs : %p  ", 0);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des pointeurs : %p  ", 0);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des pointeurs : %p  ", LONG_MAX);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des pointeurs : %p  ", LONG_MAX);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des parametres vide : %s  ", (char *)NULL);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des parametres vide : %s  ", (char *)NULL);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des parametres vide : %s  ", NULL);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des parametres vide : %s  ", NULL);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des unsigned : %u  ", -10);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des unsigned : %u  ", -10);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des hexa min : %x  ", -42);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des hexa min : %x  ", -42);
    printf("Taille : %i\n", i);
    i = ft_printf("FT  : Ca marche avec des hexa max : %X  ", 42);
    printf("Taille : %i\n", i);
    i = printf("OG  : Ca marche avec des hexa max : %X  ", 42);
    printf("Taille : %i\n", i);
    i = ft_printf("");
    printf("Taille : %i\n", i);
    i = printf("");
    printf("Taille : %i\n", i);
    i = ft_printf(0);
    printf("Taille : %i\n", i);
    i = printf(0);
    printf("Taille : %i\n", i);
    i = ft_printf(nu);
    printf("Taille : %i\n", i);
    i = printf(nu);
    printf("Taille : %i\n", i);
    i = ft_printf("FT : Ca marche avec %i %s de pointeurs : %p et double %% ", 1, "mix", &nu);
    printf("Taille : %i\n", i);
    i = printf("OG : Ca marche avec %i %s de pointeurs : %p et double %% ", 1, "mix", &nu);
    printf("Taille : %i\n", i);
    i = ft_printf("Avec %%%r et %%%%%%%% r ");
    printf("Taille : %i\n", i);
    i = printf("Avec %%%r et %%%%%%%% r ");
    printf("Taille : %i\n", i);
    return (0);
}
