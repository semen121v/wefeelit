/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validTetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:33:27 by fshade            #+#    #+#             */
/*   Updated: 2019/02/01 17:36:08 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int checklinks(char *str, int cnt)
{
	int links;

	links = 0;
	if ((cnt % 20) > 3)
		if ((str[cnt-5]) &&  ((str[cnt-5]) == '#'))
			links++;	
	if ((str[cnt-1]) &&  ((str[cnt-1]) == '#'))
		links++;

	if ((str[cnt+1]) &&  ((str[cnt+1]) == '#'))
		links++;

	if ((cnt % 20) < 15)
		if ((str[cnt+5]) &&  ((str[cnt+5]) == '#'))
			links++;
	return(links);
}


int	validTetriminos4(char *str)
{
	int links;
	int cnt;
	int bricks;

	bricks = 0;
	links = 0;
	cnt = 0;
	while (str[cnt] != '\0')
	{
		while (bricks != 20)
		{
			if (str[cnt] == '#')
				links =  links + checklinks(str, cnt); 
			cnt++;
			bricks++;
		}
		if (links != 6 && links != 8)
			return(-1);
		links = 0;
		bricks = 0;
		cnt++;
	}
	return(1);
}