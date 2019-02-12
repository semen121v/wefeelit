/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/12 19:36:43 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_sqrt(int i)
{
	int a;
	
	a = 0;
	while ((a * a) <= i)
	{
		if((a * a) == i)
			return (i);
		a++;
	}
	return(a);
}

int		count(t_mas *ptr)
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


int main (int argc, char **argv)
{
	int i;
	int j;
	//int m;
	char *str;
	t_mas *ptr;
	t_map	*map;
	t_coordinates	*coordinates;
	int	c;

	i = 0;
	ptr = NULL;
	if (argc == 2)
	{
		str = ft_read(argv[1]);
		printf ("%s\n\n", str);
		i = validTetriminos1(str);
		//printf("%d\n",i);
		if ( i == 1)
		{
			i = validTetriminos4(str);
			if (i == 1)
				if (validTetriminos2(str) == 1)
				ptr = Prepare(str);
		}
	}
	i = 0;
	j = 0;
	c =count(ptr);
	map = ft_create_map(c);
	while (j != c)
	{
		while ( i != c)
		{
			map->mas[j][i] = '.';
			printf("%c", map->mas[j][i]);
			i++;
		}
		i = 0;
		j++;
		printf ("\n");
	}
	printf ("\n");
	coordinates = creat_coordinates(ptr);


	i = 0;
	j = 0;
	while (coordinates)
	{
		while (j != 4)
		{
			while ( i != 2)
			{
				printf("%d", coordinates->coordinate[j][i]);
				i++;
			}
			i = 0;
			j++;
		}
		coordinates = coordinates->next;
		j = 0;
		printf ("\n");
	}

	c = variationValid(2, c);
	printf("\n%d",c);
	return (0);
}