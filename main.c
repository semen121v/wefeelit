/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/02 17:22:55 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int argc, char **argv)
{
	int i;
	char *str;
	t_mas *ptr;
	int j;

	i = 0;
	ptr = NULL;
	if (argc == 2)
	{
		str = ft_read(argv[1]);
		printf ("%s\n\n", str);
		i = validTetriminos1(str);
		printf("%d\n",i);
		if ( i == 1)
		{
			i = validTetriminos4(str);
			if (i == 1)
			ptr = Prepare(str);
		}
	}
	printf("\n");
	i = 0;
	j = 0;
	while (ptr)
	{
		while (j != 4)
		{
			while (i != 4)
			{	
				printf ("%c", ptr->mas[j][i]);
				i++;	
			}
			i = 0;
			j++;
			printf("\n");
		}
		j = 0;
		i = 0;
		ptr = ptr->next;		
		printf("\n");
	}
	//printf("\n%d\n",i);
	return (0);
}