/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/18 14:34:48 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int fillit(t_mas *ptr)
{
	t_map	*map;
	t_coordinates	*first;
	t_coordinates	*first1;
	t_coordinates	*size;
	t_coordinates	*dot;
	int	c;
	char	**mas;
    char    *mas1;

	c =count(ptr);
	printf("\n%d\n",c);
	map = ft_create_map(c);
	dot =  creat_coordinates(ptr);
	size = creat_size(ptr);
	first = dot;
	first1 = size;
	map = newtetrimo(first, first1);
	while (map)
	{
		mas = map->mas;
		while (*mas)
    	{
    		mas1 = *mas;
        	while(*mas1)
        	{   
				printf("%c", *mas1);
            	mas1++;
        	}
			printf("\n");
        mas++;
    	}
		printf("\n");
		map = map->next;
	}

	c = variationValid(2, c);
	printf("%d\n",c);
	return (1);
}