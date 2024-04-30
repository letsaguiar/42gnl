/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letsaguiar <letsaguiar@yandex.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:40 by letsaguiar        #+#    #+#             */
/*   Updated: 2024/04/30 10:39:42 by letsaguiar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char    *get_next_line(int fd);

void    *ft_calloc(size_t count, size_t size);

char    *ft_strchr(const char *s, char c);

size_t  ft_strlen(const char *s);

char    *ft_strjoin(const char *s1, const char *s2);

#endif