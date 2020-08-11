/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   satan.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:00:59 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/11 17:17:01 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_satan(t_satan *sn)
{
	while (sn->n < 25)
	{
		sn->aa = sn->a * sn->a - sn->b * sn->b;
		sn->bb = 0.0666 * 2 * sn->a * sn->b;
		sn->a = sn->aa - 0.666 + sn->ca;
		sn->b = sn->bb + sn->cb;
		if (sn->a + sn->b > 16)
			break ;
		sn->n++;
	}
}
