/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:17 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/18 14:31:03 by fshade           ###   ########.fr       */
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
	char			**mas;
    struct s_map	*next;
    struct s_map	*prev;
}				t_map;

typedef struct	s_coordinates
{   
	int			        dot[4][2];
    struct s_coordinates	*next;
}				t_coordinates;


int             fillit(t_mas *ptr);
int             validTetriminos1(char *str);
int             validTetriminos2(char *str);
int             checklinks(char *str, int cnt, int j);
int             validTetriminos3(char *str);
t_mas           *Prepare(char *str);
void            Newmas(char *str, t_mas *mas, int i, int j);
int             ft_readlen(char *fd);
char            *ft_read(char *fd);
t_map           *ft_create_map(int i);
int             variationValid(int i, int m);
t_coordinates   *creat_coordinates(t_mas    *ptr);
t_map           *newtetrimo(t_coordinates *dot, t_coordinates *size);
t_coordinates   *creat_size(t_mas    *ptr);
int		        count(t_mas *ptr);


#endif
