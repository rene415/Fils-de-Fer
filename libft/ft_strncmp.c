/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:52:29 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 22:01:03 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int		i;
	unsigned const char *s1_tmp;
	unsigned const char *s2_tmp;

	s1_tmp = (unsigned const char*)s1;
	s2_tmp = (unsigned const char*)s2;
	i = 0;
	while (s1_tmp[i] == s2_tmp[i] && i < (n - 1) && s1_tmp[i] && s2_tmp[i])
		i++;
	if (n == 0)
		return (0);
	return (s1_tmp[i] - s2_tmp[i]);
}
