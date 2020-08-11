/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:18:31 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/31 16:19:06 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *str, size_t n)
{
	char		*destination;
	const char	*string;
	size_t		bytes;

	destination = dst;
	string = str;
	bytes = n;
	while (*string && bytes > 1)
	{
		*(destination++) = *(string++);
		--bytes;
	}
	if (bytes && n)
		*destination = '\0';
	return (ft_strlen(str));
}
