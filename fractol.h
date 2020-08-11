/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:54:05 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/11 17:17:23 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCREEN_W 640
# define SCREEN_H 640

# include "libft.h"
# include "/usr/X11/include/mlx.h"
# include <math.h>

typedef struct	s_mouse
{
	int		x;
	int		y;
	int		xprev;
	int		yprev;
}				t_mouse;

typedef struct	s_image
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		line;
	int		endian;
	double	minx;
	double	maxx;
	double	miny;
	double	maxy;
	double	offsetx;
	double	offsety;
	double	zoom;
}				t_image;

typedef struct	s_prog
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_mouse		mouse;
	int			type;
}				t_prog;

enum			e_mouse
{
	LMB = 1,
	RMB = 2,
	MMB = 3,
	WhDn = 4,
	WhUp = 5
};

enum			e_key
{
	ESC = 53,
	numPlus = 69,
	numMin = 78,
	vk_left = 123,
	vk_right = 124,
	vk_down = 125,
	vk_up = 126
};

typedef struct	s_mbrot
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	double		bright;
	int			x;
	int			y;
	int			n;
}				t_mbrot;

typedef struct	s_julia
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	double		bright;
	double		twoab;
	int			x;
	int			y;
	int			n;
}				t_julia;

typedef struct	s_satan
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	double		bright;
	int			x;
	int			y;
	int			n;
}				t_satan;

typedef struct	s_fuck_norm
{
	double	o;
	double	omin;
	double	omax;
	double	nmin;
	double	nmax;
}				t_fuck_norm;

/*
** Event handlers
*/

int				mouse_key(int button, int x, int y, void *param);
int				keyboard(int key, void *param);

void			ft_exit(char *str);
double			normalize(t_fuck_norm v);

void			store_image_mandelbrot(t_image *image, int color);
void			store_image_satan(t_image *image, int color);
void			store_image_julia(t_image *image, int color,
				double ox, double oy);

int				calculate_color(double bright);
void			loop_satan(t_satan *sn);

#endif
