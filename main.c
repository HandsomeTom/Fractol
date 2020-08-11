/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:52:12 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/10 17:48:20 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Oh shit what up
** This bad boi gonna freak the hell out of you.
*/

#include "fractol.h"

static int			validate_arg(char *str)
{
	if (strcmp(str, "mandelbrot") == 0)
		return (1);
	if (strcmp(str, "julia") == 0)
		return (2);
	if (strcmp(str, "satan") == 0)
		return (3);
	return (0);
}

int					calculate_color(double bright)
{
	int		channel;
	int		color;

	channel = 255 * bright;
	color = channel;
	color = (bright < 0.2 || bright > 0.5) ?
	(color | ((channel / 2) << 8)) : (color | ((channel / 4) << 8));
	color = (bright < 0.2) ?
	(color | ((channel * 4) << 16)) : (color | ((channel) << 16));
	color = (bright > 0.3 && bright < 0.6) ?
	(color | ((channel) << 24)) : (color | ((channel / 4) << 24));
	return (color);
}

int					calculate_color_satan(double bright)
{
	int		channel;
	int		color;

	channel = 255 * bright;
	color = channel;
	color = (color | (channel) << 8);
	color = (color | (channel) << 16);
	color = (color | ((0) << 24));
	return (color);
}

int					mouse_move(int x, int y, void *param)
{
	t_prog	*prog;

	prog = (t_prog *)param;
	prog->mouse.x = x;
	prog->mouse.y = y;
	if (prog->type == 2)
	{
		store_image_julia(&prog->image, 0xFFFFFF,
			normalize((t_fuck_norm){prog->mouse.x, 0, SCREEN_W, -1, 1}),
			normalize((t_fuck_norm){prog->mouse.y, 0, SCREEN_H, -1, 1}));
		mlx_put_image_to_window(prog->mlx, prog->win, prog->image.ptr, 0, 0);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_prog		prog;

	if (argc != 2)
		ft_exit("Nub. Use: ./fractol [mandelbrot, julia, satan]");
	if ((prog.type = validate_arg(argv[1])) == 0)
		ft_exit("Stop ffs. Use: ./fractol [mandelbrot, julia, satan]");
	prog.mlx = mlx_init();
	prog.image.maxx = 2;
	prog.image.maxy = 2;
	prog.image.minx = -2;
	prog.image.miny = -2;
	prog.win = mlx_new_window(prog.mlx, SCREEN_W, SCREEN_H, "Windows Vista");
	prog.image.ptr = mlx_new_image(prog.mlx, SCREEN_W, SCREEN_H);
	prog.image.data = (int *)mlx_get_data_addr(prog.image.ptr, &prog.image.bpp,
		&prog.image.line, &prog.image.endian);
	prog.image.line /= 4;
	mlx_key_hook(prog.win, &keyboard, &prog);
	mlx_mouse_hook(prog.win, &mouse_key, &prog);
	mlx_hook(prog.win, 6, 0, &mouse_move, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
