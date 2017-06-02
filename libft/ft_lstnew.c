/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:16:28 by rramirez          #+#    #+#             */
/*   Updated: 2017/02/17 22:53:54 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;
	void	*tmp;

	if (!(a = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (a)
	{
		if (content == NULL)
		{
			a->content = NULL;
			a->content_size = 0;
		}
		else
		{
			tmp = (void *)malloc(content_size);
			tmp = ft_memcpy(tmp, content, content_size);
			a->content = tmp;
			a->content_size = content_size;
		}
	}
	a->next = NULL;
	return (a);
}
