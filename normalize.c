/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:14:08 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/10 17:50:23 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	normalize(t_fuck_norm v)
{
	double ret;

	ret = (v.o - v.omin) / (v.omax - v.omin) * (v.nmax - v.nmin) + v.nmin;
	return (ret);
}
