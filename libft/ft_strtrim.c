/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:51:26 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/11 21:32:12 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	h;
	size_t	i;
	size_t	len;
	char	*mem;

	h = 0;
	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[h] == ' ' || s[h] == '\n' || s[h] == '\t')
		h++;
	if (h == ft_strlen(s))
		return (ft_strnew(1));
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	len = (i - h) + 1;
	if (!(mem = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len-- > 0)
		mem[i++] = s[h++];
	mem[i] = '\0';
	return (mem);
}
