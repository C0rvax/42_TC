/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:29:08 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/23 13:13:53 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_mallocstash(char *stash);
void	gnl_bzero(void *s, size_t size);
char	*gnl_cleanstash(char *stash, unsigned int start, size_t len);
int		gnl_isline(char *s);
char	*gnl_getline(char *s, size_t lineend);
char	*gnl_read(int fd, char *stash);
char	*get_next_line(int fd);

#endif
