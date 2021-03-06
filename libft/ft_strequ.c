/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:32:37 by fshade            #+#    #+#             */
/*   Updated: 2018/12/25 23:04:20 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	char	*s3;
	char	*s4;

	s3 = (char*)s1;
	s4 = (char*)s2;
	i = 0;
	if (!s4 || !s3)
		return (0);
	while ((s3[i] == s4[i]) && (s3[i] != '\0') && (s4[i] != '\0'))
		i++;
	if (s3[i - 1] == s4[i - 1] && (s3[i] == '\0' && s4[i] == '\0'))
		return (1);
	return (0);
}
