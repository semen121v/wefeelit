/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinaes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:28:46 by fshade            #+#    #+#             */
/*   Updated: 2019/02/12 19:39:12 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coordinates   *creat_coordinates(t_mas    *ptr)
{
    t_coordinates	*coordinates;
	t_coordinates	*first;
    int i;
	int j;
	int m;
	
	if ((coordinates = (t_coordinates*)malloc(sizeof(t_coordinates))) == NULL)
		return (NULL);
	first = coordinates;
	while (ptr)
	{	
		m = 0;
		j = 0;
		while (j!=4)
		{
			i = 0;
			while (i != 4)
			{
				if (ptr->mas[j][i] == '#')
				{
					coordinates->coordinate[m][0] = j;
					coordinates->coordinate[m][1] = i;
					m++;
				}
				i++;
			} 
			j++;
		}
		if (ptr->next != NULL)
		{
			coordinates->next = (t_coordinates*)malloc(sizeof(t_coordinates));
			coordinates = coordinates->next;
		}
		ptr = ptr->next;
	}
	coordinates->next = NULL;
    return (first);
}