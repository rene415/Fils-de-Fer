/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:47:33 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/19 16:22:35 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t	c_word;
	char	**mem;
	size_t	i;

	c_word = 0;
	if (!s || !c)
		return (0);
	if (!(mem = (char **)malloc(sizeof(char *) * ft_word_count(s, c) + 1)))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			mem[c_word] = (char *)malloc(sizeof(char) * (ft_letters(s, c) + 1));
			while (ft_letters(s, c) > 0)
				mem[c_word][i++] = *s++;
			mem[c_word][i] = '\0';
			c_word++;
		}
		else
			s++;
	}
	mem[c_word] = 0;
	return (mem);
}
