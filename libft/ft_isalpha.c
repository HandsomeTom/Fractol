/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:47:20 by tmaarela          #+#    #+#             */
/*   Updated: 2019/10/24 19:39:12 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isalpha
** Check if the ascii value of c is alphabetic.
*/

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}