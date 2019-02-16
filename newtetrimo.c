/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtetrimo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:55:33 by fshade            #+#    #+#             */
/*   Updated: 2019/02/15 17:50:31 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void static createnewtetrimo2(t_map *newtetrimo, t_coordinates *dot, int i, int j)
{
    int     k;

    k = 3;
    while (k != -1)
    {
        i = dot->dot[k][1] - dot->dot[0][1];
        j = dot->dot[k][0] - dot->dot[0][0];
        newtetrimo->mas[j][i] = '#';

        k--;
    }
}

void static createnewtetrimo1(t_map *newtetrimo,    int i, int j)
{
    if ((newtetrimo->mas=(char**)malloc(sizeof(char*) * (j + 1))) == NULL)
        return;
    newtetrimo->mas[j] = NULL;
    while (j != 0)
    {
        if ((newtetrimo->mas[j - 1]=(char*)malloc(sizeof(char*) * i)) == NULL)
            return ;
        ft_memset(newtetrimo->mas[j - 1],'.', i);
        j--;
    }
}

t_map *newtetrimo(t_coordinates *dot)
{   
    t_map   *newtetrimo;
    t_map   *first;
    int     i;
    int     j;

    if (!dot)
        return  (NULL);
     if ((newtetrimo= (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
    first = newtetrimo;
    while (dot)
    {
        i = dot->dot[3][1] - dot->dot[0][1] + 1;
        j = dot->dot[3][0] - dot->dot[0][0] + 1;
        createnewtetrimo1(newtetrimo,i, j);
        createnewtetrimo2(newtetrimo,dot,i,j);
        if (dot->next != NULL)
        {
            newtetrimo->next = (t_map*)malloc(sizeof(t_map));
            newtetrimo = newtetrimo->next;
        }
        dot = dot->next;
    }
    return (first);
}