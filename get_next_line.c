/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letsaguiar <letsaguiar@yandex.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:00:44 by letsaguiar        #+#    #+#             */
/*   Updated: 2024/04/30 12:14:05 by letsaguiar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *read_from_file(int fd)
{
    char    *buffer;
    size_t   bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof (char));
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

char    *remove_from_left(char *left)
{
    char    *ptr;
    char    *chr;

    chr = ft_strchr(left, '\n');
    if (!chr)
        ptr = NULL;
    else
        ptr = ft_substr(chr + 1, 0, ft_strlen(chr + 1));
    free(left);
    return (ptr);
}

char    *extract_line(const char *left)
{
    size_t  length;

    if (!left)
        return (NULL);
    length = 0;
    while (left[length] && left[length] != '\n')
        length++;
    return (ft_substr(left, 0, length + 1));
}

char    *get_next_line(int fd)
{
    char        *buffer;
    char        *line;
    static char *left;
    
    while (!ft_strchr(left, '\n') && (buffer = read_from_file(fd)))
        left = append_to_left(left, buffer);
    line = extract_line(left);
    left = remove_from_left(left);
    return (line);
}