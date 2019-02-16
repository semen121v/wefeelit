/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/16 15:39:18 by fshade           ###   ########.fr       */
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
	//int j;
	//int m;
	char *str;
	t_mas *ptr;
	//t_map	*map;
	//t_coordinates	*first;
	//t_coordinates	*dot;
	//int	c;
	//    char	**mas;
   // char    *mas1;

	i = 0;
	ptr = NULL;
	if (argc == 2)
	{
		if ((str = ft_read(argv[1])) == NULL)
		{
					ft_putstr("error\n");
					return (0);
		}

		//printf ("%s\n\n", str);
		i = validTetriminos1(str);
		//printf("%d\n",i);
		if (i == 1)
		{
			i = validTetriminos3(str);
			if (i == 1)
			{
				if (validTetriminos2(str) == 1)
					ptr = Prepare(str);
				else
				{
					ft_putstr("error\n");
					return (0);
				}
			}
			else
				{
					ft_putstr("error\n");
					return (0);
				}
		}
		else
		{
					ft_putstr("error\n");
					return (0);
				}
	}
	// i = 0;
	// j = 0;
	// c =count(ptr);
	// map = ft_create_map(c);
	// while (j != c)
	// {
	// 	while ( i != c)
	// 	{
	// 		map->mas[j][i] = '.';
	// 		printf("%c", map->mas[j][i]);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	j++;
	// 	printf ("\n");
	// }
	// printf ("\n");
	// dot = creat_coordinates(ptr);
	// first = dot;

	// i = 0;
	// j = 0;
	// while (dot)
	// {
	// 	while (j != 4)
	// 	{
	// 		while ( i != 2)
	// 		{
	// 			printf("%d", dot->dot[j][i]);
	// 			i++;
	// 		}
	// 		i = 0;
	// 		j++;
	// 	}
	// 	dot = dot->next;
	// 	j = 0;
	// 	printf ("\n");
	// }
	// map = newtetrimo(first);
	// while (map)
	// {
	// 	mas = map->mas;
	// 	while (*mas)
    // 	{
    // 		mas1 = *mas;
    //     	while(*mas1)
    //     	{   
	// 			printf("%c", *mas1);
    //         	mas1++;
    //     	}
	// 		printf("\n");
    //     mas++;
    // 	}
	// 	printf("\n");
	// 	map = map->next;
	// }

	// c = variationValid(2, c);
	// printf("\n%d",c);
	 return (0);
}