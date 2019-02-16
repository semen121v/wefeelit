/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:39:41 by fshade            #+#    #+#             */
/*   Updated: 2019/02/16 20:07:46 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map       *ft_create_map(int i)
{   
    t_map   *map;
    int     j;

    j = 0;
    if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
    if ((map->mas=(char**)malloc(sizeof(char*) * i)) == NULL)
        return (NULL);
    while (j != i)
    {
        if ((map->mas[j]=(char*)malloc(sizeof(char*) * i)) == NULL)
            return (NULL);
        j++;
    }
    return (map);
}

int     variationValid(int k, int m)
{
    int     i;
    int     j;
    int     c;

    c = 0;
    i = k - 1;
    j = 1;
    while (j != m)
    {
        while (i != m)
        {
            c++;
            i++;
        }
        i = k - 1;
        j++;
    }
    return(c);
}