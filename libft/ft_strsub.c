/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:49:27 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 10:15:51 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(mem = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[start] != '\0')
	{
		mem[i] = s[start];
		i++;
		start++;
	}
	mem[i] = '\0';
	return (mem);
}
