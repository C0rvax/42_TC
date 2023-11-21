#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ifforest(char c, va_list arg);
int		print_putchar(char c);
int		print_putstr(char *s);
int		print_number(int n);
int		print_unsigned(unsigned int n);
int		print_hex(int nbr, int mode);

#endif
