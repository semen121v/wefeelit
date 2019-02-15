/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newmas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:14:29 by fshade            #+#    #+#             */
/*   Updated: 2019/02/13 17:32:47 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	Newmas(char *str, t_mas *mas, int i, int j)
{
	while (*str != '\0')
	{
		while (j != 4 && *str != '\n' && *str != '\0')	
		{	
			mas->mas[j][i] = *str;
			i++;
			str++;	
		}
		if (*str == '\n' && i == 4)
		{
			i = 0;
			j++;
			str++;
		}
		else if (*str != '\0')
		{
			j = 0;
			i = 0;
			mas->next = (t_mas*)malloc(sizeof(t_mas));
			mas->next->prev = mas;
			mas = mas->next;
			str++;			
		}
	}	
	mas->next = NULL;
}

t_mas   *Prepare(char *str)
{
	t_mas	*mas;
	t_mas	*first;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((mas = (t_mas*)malloc(sizeof(t_mas))) == NULL)
		return (NULL);
	mas->prev = NULL;
	first = mas;
	Newmas(str, mas, i, j);
	return (first);
}