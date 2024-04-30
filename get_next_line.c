/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letsaguiar <letsaguiar@yandex.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:00:44 by letsaguiar        #+#    #+#             */
/*   Updated: 2024/04/30 11:02:05 by letsaguiar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *read_from_file(int fd)
{
    char    *buffer;
    size_t   bytes_read;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        free(buffer);
        return (NULL);    
    }
    return (buffer);
}

char    *append_to_left(char *left, char *buffer)
{
    char    *ptr;
    
    ptr = ft_strjoin(left, buffer);
    if (left)
        free(left);
    if (buffer)
        free(buffer);
    return (ptr);
}

char    *get_next_line(int fd)
{
    char        *buffer;
    char        *left;
    
    left = NULL;
    while (1)
    {
        buffer = read_from_file(fd);
        if (!buffer)
            break;
        left = append_to_left(left, buffer);
        if (ft_strchr(left, '\n'))
            break;
    }
    return (left);
}