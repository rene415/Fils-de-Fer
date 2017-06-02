/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 21:47:14 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 19:23:48 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_tmp;
	const char	*src_tmp;
	size_t		n;
	size_t		len;
	size_t		diff;

	dst_tmp = (char*)dst;
	src_tmp = src;
	n = size;
	while (*dst_tmp && n > 0)
	{
		dst_tmp++;
		n--;
	}
	diff = dst_tmp - dst;
	len = diff + ft_strlen(src);
	n = size - diff;
	if (n <= 0)
		return (len);
	while (n-- > 1 && src_tmp != '\0')
		*dst_tmp++ = *src_tmp++;
	*dst_tmp = '\0';
	return (len);
}
