/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:11:38 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/10 23:12:42 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = dest;
	while (i < len)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i < len)
			{
				dest[i] = '\0';
				i++;
			}
		}
		else if (src[i] != '\0')
			i++;
	}
	return (temp);
}
