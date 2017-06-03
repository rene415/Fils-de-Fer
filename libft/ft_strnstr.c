/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:01:38 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/19 20:05:47 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	char		*i;
	char		*a;
	const char	*str;

	i = (char *)s;
	a = (char *)to_find;
	str = i + len;
	if (ft_strcmp(i, a) == 0)
		return (a);
	while (*s && s <= str)
	{
		i = (char *)s;
		if (*s == *to_find)
		{
			while (*i && *a && *i == *a && (i++ < str))
				a++;
		}
		if (!*a)
			return ((char *)s);
		a = (char *)to_find;
		s++;
	}
	return (0);
}
