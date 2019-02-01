/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:42 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/01 15:40:57 by fshade           ###   ########.fr       */
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

int		validTetriminos1(char *str)
{
	int		i;
	
	i = 19;
	while (str[i] != '\0')
		{
			if (str[i + 1] == '\n' && str[i + 1] != '\0')
				i = i + 2;
			else
				return (-1);
			i = i + 19;		
		}
	return (1);
}

int validTetriminos2(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*str != '\0')
	{
		while (k != 20 && *str != '\0')
		{
			if (*str == '#')
				i++;
			if (*str == '.')
				j++;
			k++;
			str++;
		}
		k = 0;
		if (i == 4 && j == 12)
		{
			i = 0;
			j = 0;
		}
		else
			return (-1);
		str++;
	}
	return (1);
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
	else
	{
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
				if (*str == '\n' && j != 4 && i != 4)
					return (NULL);
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
		printf("%d",i);
		if ( i == 1)
		{
			i = validTetriminos2(str);
			printf("%d",i);
		}
		//printf ("%c\n%d", ptr->mas[0][0],i);
	}
	return (0);
}