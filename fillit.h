/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:17 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/18 19:16:23 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct	s_mas
{
	char			mas[4][4];
	struct s_mas	*next;
	struct s_mas	*prev;
}				t_mas;

typedef struct	s_map
{
	int				x;
	int				y;
	char			**mas;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

typedef struct	s_coordinates
{
	int						dot[4][2];
	struct s_coordinates	*next;
}				t_coordinates;

int				fillit(t_mas *ptr);
int				valid_tetriminos1(char *str);
int				valid_tetriminos2(char *str, int i, int j);
int				valid_tetriminos3(char *str);
int				checklinks(char *str, int cnt, int j);
int				variation_valid(int i, int m);
int				count(t_mas *ptr);
char			*ft_read(char *fd);
void			cleanlist(t_mas *ptr);
t_mas			*prepare(char *str);
t_map			*ft_create_map(int i);
t_coordinates	*creat_coordinates(t_mas *ptr);
t_map			*newtetrimo(t_coordinates *dot, t_coordinates *size);
t_coordinates	*creat_size(t_mas *ptr);

#endif
