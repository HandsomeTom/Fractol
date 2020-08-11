/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:28:17 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/11 17:24:06 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			wheel_down(t_prog *prog)
{
	prog->image.minx *= 0.85;
	prog->image.maxx *= 0.85;
	prog->image.miny *= 0.85;
	prog->image.maxy *= 0.85;
}

static void			wheel_up(t_prog *prog)
{
	prog->image.minx /= 0.85;
	prog->image.maxx /= 0.85;
	prog->image.miny /= 0.85;
	prog->image.maxy /= 0.85;
}

static void			right_btn(t_prog *prog)
{
	prog->image.offsetx = normalize((t_fuck_norm){prog->mouse.x, 0, SCREEN_W,
	prog->image.minx + prog->image.offsetx, prog->image.maxx +
	prog->image.offsetx});
	prog->image.offsety = normalize((t_fuck_norm){prog->mouse.y, 0, SCREEN_W,
	prog->image.miny + prog->image.offsety, prog->image.maxy +
	prog->image.offsety});
}

int					mouse_key(int button, int x, int y, void *param)
{
	t_prog	*prog;

	prog = (t_prog *)param;
	if (button == WhDn)
		wheel_down(prog);
	if (button == WhUp)
		wheel_up(prog);
	if (button == RMB)
		right_btn(prog);
	if (prog->type == 2)
	{
		store_image_julia(&prog->image, 0xFFFFFF,
			normalize((t_fuck_norm){prog->mouse.x, 0, SCREEN_W, -1, 1}),
			normalize((t_fuck_norm){prog->mouse.y, 0, SCREEN_H, -1, 1}));
	}
	else if (prog->type == 1)
		store_image_mandelbrot(&prog->image, 0xFFFFFF);
	else
		store_image_satan(&prog->image, 0xFFFFFF);
	mlx_put_image_to_window(prog->mlx, prog->win, prog->image.ptr, 0, 0);
	return (0);
}
