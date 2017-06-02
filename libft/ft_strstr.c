/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:36:13 by rramirez          #+#    #+#             */
/*   Updated: 2017/01/29 16:41:31 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char *i;
	char *a;

	i = 0;
	a = 0;
	if (!*to_find)
		return ((char *)str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = (char *)str + 1;
			a = (char *)to_find + 1;
			while (*i && *a && *i == *a)
			{
				i++;
				a++;
			}
			if (!*a)
				return ((char *)str);
		}
		str++;
	}
	return (0);
}
