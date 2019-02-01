/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/01 18:46:01 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_readlen(char *fd)
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

char *ft_read(char *fd)
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

t_mas	*validTetriminos3(char *str)
{
	t_mas	*mas;
	t_mas	*first;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((mas = (t_mas*)malloc(sizeof(t_mas))) == NULL)
		return (NULL);
	first = mas;
	while (*str != '\0')
		{
			while (j != 4 && *str != '\n' && *str != '\0')
			{	
				mas->mas[j][i] = *str;
				printf ("%c", mas->mas[j][i]);
				i++;
				str++;	
			}
			if (*str == '\n' && i == 4)
			{
				i = 0;
				j++;
				str++;
				printf("\n");
			}
			else  
			{
					j = 0;
					i = 0;
					mas->next = (t_mas*)malloc(sizeof(t_mas));
					mas = mas->next;
					str++;			
					printf("\n");
			}
		}
	mas->next = NULL;
	return (first);
}

int main (int argc, char **argv)
{
	int i;
	char *str;
	t_mas *ptr;

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
			ptr = validTetriminos3(str);
		}
	}
	return (0);
}