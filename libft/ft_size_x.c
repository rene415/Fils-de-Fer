/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:46:38 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/26 20:14:36 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_size_x(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
