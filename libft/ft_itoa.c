/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stritoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:52:57 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 10:16:26 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*mem;
	size_t	len;

	len = ft_int_len(n);
	if (n >= 0)
		len--;
	if (!(mem = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	mem[len + 1] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		mem[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		mem[len] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
	if (n >= 0 && n <= 9)
		mem[len] = n + 48;
	return (mem);
}
