/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:34:06 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/11 17:19:35 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			num_plus(t_prog *prog)
{
	prog->image.minx *= 0.85;
	prog->image.maxx *= 0.85;
	prog->image.miny *= 0.85;
	prog->image.maxy *= 0.85;
}

static void			num_minus(t_prog *prog)
{
	prog->image.minx /= 0.85;
	prog->image.maxx /= 0.85;
	prog->image.miny /= 0.85;
	prog->image.maxy /= 0.85;
}

int					keyboard(int key, void *param)
{
	t_prog	*prog;

	prog = (t_prog *)param;
	if (key == ESC)
		exit(0);
	if (key == numPlus)
		num_plus(prog);
	if (key == numMin)
		num_minus(prog);
	if (prog->type == 2)
		store_image_julia(&prog->image, 0xFFFFFF,
			normalize((t_fuck_norm){prog->mouse.x, 0, SCREEN_W, -1, 1}),
			normalize((t_fuck_norm){prog->mouse.y, 0, SCREEN_H, -1, 1}));
	else if (prog->type == 1)
		store_image_mandelbrot(&prog->image, 0xFFFFFF);
	else
		store_image_satan(&prog->image, 0xFFFFFF);
	mlx_put_image_to_window(prog->mlx, prog->win, prog->image.ptr, 0, 0);
	return (0);
}
