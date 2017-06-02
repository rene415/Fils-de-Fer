/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:46:28 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 19:21:06 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int				neg;
	int				nb;
	unsigned char	*s;

	s = (unsigned char*)str;
	neg = 0;
	nb = 0;
	while (ft_spaces(*s))
		s++;
	if (*s == '-')
		neg++;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nb = nb * 10 + (*s - 48);
		s++;
	}
	if (neg == 1)
		return (nb * -1);
	else
		return (nb);
}
