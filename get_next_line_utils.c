/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letsaguiar <letsaguiar@yandex.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:13:28 by letsaguiar        #+#    #+#             */
/*   Updated: 2024/04/30 10:43:11 by letsaguiar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t count, size_t size)
{
    unsigned char   *ptr;
    unsigned int    i;

    if (count > SIZE_MAX / size)
        return (NULL);
    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < count * size)
    {
        ptr[i] = 0;
        i++;
    }
    return (ptr);
}

char    *ft_strchr(const char *s, char c)
{
    if (!s)
        return (NULL);
    while (*s && *s != c)
        s++;
    if (*s == c)
        return ((char *) s);
    return (NULL);
}

size_t  ft_strlen(const char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *ptr;
    size_t  length;
    size_t  i;
    size_t  j;

    length = ft_strlen(s1) + ft_strlen(s2) + 1;
    if (!length)
        return (NULL);
    ptr = ft_calloc(length, sizeof (char));
    if (!ptr)
        return (NULL);
    i = 0;
    j = 0;
    while (i < length && j < ft_strlen(s1))
        ptr[i++] = s1[j++];
    j = 0;
    while (i < length && j < ft_strlen(s2))
        ptr[i++] = s2[j++];
    return (ptr);
}