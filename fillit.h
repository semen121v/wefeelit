/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:17 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/02 19:31:45 by fshade           ###   ########.fr       */
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
    struct s_mas	*next;
    struct s_mas	*prev;
}				t_map;



int         validTetriminos1(char *str);
int         validTetriminos2(char *str);
int         checklinks(char *str, int cnt);
int         validTetriminos4(char *str);
t_mas       *Prepare(char *str);
void        Newmas(char *str, t_mas *mas, int i, int j);
int         ft_readlen(char *fd);
char        *ft_read(char *fd);
t_map       *ft_create_map(int i);


#endif
