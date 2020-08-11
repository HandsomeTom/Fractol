/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:42:40 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/31 16:34:34 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*link;

	if ((link = (t_list *)malloc(sizeof(t_list))))
	{
		link->next = NULL;
		link->content = NULL;
		link->content_size = 0;
		if (content && (link->content = malloc(content_size)))
		{
			ft_memcpy(link->content, content, content_size);
			link->content_size = content_size;
		}
	}
	return (link);
}
