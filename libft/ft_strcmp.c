/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:50:06 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 21:48:54 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned const char *s1_tmp;
	unsigned const char *s2_tmp;

	s1_tmp = (unsigned const char*)s1;
	s2_tmp = (unsigned const char*)s2;
	i = 0;
	while (s1_tmp[i] == s2_tmp[i] && s1_tmp[i] != '\0')
	{
		i++;
	}
	return (s1_tmp[i] - s2_tmp[i]);
}
