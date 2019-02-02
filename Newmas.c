/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newmas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:14:29 by fshade            #+#    #+#             */
/*   Updated: 2019/02/02 17:22:07 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_readlen(char *fd)
{
	int i;
	int file;
	char tmp;

	i = 0;
	file = open(fd, O_RDONLY);
	while (read(file, &tmp, 1))
	{
		if (tmp != '.' && tmp != '#' && tmp != '\n')
			return (-1);
		i++;
	}
	if (i > 545 || i < 20)
		return (-1);
	close (file);
	return (i);
}

char    *ft_read(char *fd)
{
	int file;
	char *str;
	char tmp;
	int i;

	i = 0;
	if (ft_readlen(fd) == -1)
		return(NULL);
	else
		str = ft_strnew(ft_readlen(fd) + 1);
	file = open(fd, O_RDONLY);
	while (read(file, &tmp, 1))
	{
		str[i++] = tmp;
	}
	close (file);
	return (str);
}

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