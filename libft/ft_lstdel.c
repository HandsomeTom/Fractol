/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:56:03 by tmaarela          #+#    #+#             */
/*   Updated: 2020/02/13 16:00:39 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **head, void (*del)(void *, size_t))
{
	if (*head != NULL)
	{
		if ((*head)->next != NULL)
			ft_lstdel(&(*head)->next, del);
		del((*head)->content,
			(*head)->content_size);
		free(*head);
		*head = NULL;
	}
}
