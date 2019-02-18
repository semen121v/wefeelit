/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:39:41 by fshade            #+#    #+#             */
/*   Updated: 2019/02/18 18:39:24 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*ft_create_map(int i)
{
	t_map	*map;
	int		j;

	j = 0;
	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((map->mas = (char**)malloc(sizeof(char*) * i)) == NULL)
		return (NULL);
	while (j != i)
	{
		if ((map->mas[j] = (char*)malloc(sizeof(char*) * i)) == NULL)
			return (NULL);
		j++;
	}
	return (map);
}

static int	ft_sqrt(int i)
{
	int a;

	a = 0;
	while ((a * a) <= i)
	{
		if ((a * a) == i)
			return (a);
		a++;
	}
	return (a);
}

int			count(t_mas *ptr)
{
	int		i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (ft_sqrt(i * 4));
}

int			variation_valid(int k, int m)
{
	int		i;
	int		j;
	int		c;

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
	return (c);
}
