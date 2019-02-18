/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:04:29 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/18 19:10:49 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_mas	*check_tetrimisions2(int i, char *str)
{
	t_mas *ptr;

	i = valid_tetriminos3(str);
	if (i == 1)
	{
		if (valid_tetriminos2(str, 0, 0) == 1)
		{
			ptr = prepare(str);
			return (ptr);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

static t_mas	*check_tetrimisions1(int i, char *argv)
{
	char *str;

	if ((str = ft_read(argv)) == NULL)
		return (NULL);
	i = valid_tetriminos1(str);
	if (i == 1)
		return (check_tetrimisions2(i, str));
	else
		return (NULL);
	return (NULL);
}

int				main(int argc, char **argv)
{
	int		i;
	t_mas	*ptr;

	i = 0;
	if (argc == 2)
	{
		ptr = check_tetrimisions1(i, argv[1]);
		if (ptr == NULL)
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
	i = fillit(ptr);
	return (0);
}
