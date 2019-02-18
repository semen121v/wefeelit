/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:04:29 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/18 14:33:48 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_mas *checkTetrimisions2(int i, char *str)
{	
	t_mas *ptr;
	
	i = validTetriminos3(str);
	if (i == 1)
	{
		if (validTetriminos2(str) == 1)
		{
			ptr = Prepare(str);
			return (ptr);
		}
		else
		{
			ft_putstr("error2\n");
			return (NULL);
		}
	}
	else 
	{
		ft_putstr("error2\n");
		return (NULL);
	}
}

static t_mas *checkTetrimisions1(int i, char *argv)
{
	char *str;

	if ((str = ft_read(argv)) == NULL)
	{
		ft_putstr("error1\n");
		return (NULL);
	}
	i = validTetriminos1(str);
	if ( i == 1)
		return (checkTetrimisions2(i, str));
	else
	{
		ft_putstr("error3\n");
		return (NULL);
	}
	return (NULL);
}

int main (int argc, char **argv)
{
    int     i;
	t_mas   *ptr;

    i = 0;
	if (argc == 2)
	{
		ptr = checkTetrimisions1(i,argv[1]);
		if ( ptr == NULL)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else 
	{
		ft_putstr("error5\n");
		return (0);
	}
    i = fillit(ptr);
    printf("%d", i);
    return (0);
}