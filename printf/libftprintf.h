#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ifforest(char c, va_list arg);
int		print_putchar(char c);
