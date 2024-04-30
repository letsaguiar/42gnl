/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letsaguiar <letsaguiar@yandex.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:13:28 by letsaguiar        #+#    #+#             */
/*   Updated: 2024/04/30 10:15:50 by letsaguiar       ###   ########.fr       */
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