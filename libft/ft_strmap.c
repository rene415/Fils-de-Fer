/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:52:06 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 17:37:33 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mem;

	i = 0;
	if (!s)
		return (0);
	if (!(mem = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (*s)
	{
		mem[i] = f(*s);
		s++;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
