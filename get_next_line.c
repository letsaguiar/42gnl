/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letsaguiar <letsaguiar@yandex.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:00:44 by letsaguiar        #+#    #+#             */
/*   Updated: 2024/04/30 10:16:48 by letsaguiar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char    *get_next_line(int fd)
{
    char    *line;
    
    line = read_from_file(fd);
    return (line);
}