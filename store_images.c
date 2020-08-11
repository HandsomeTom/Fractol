/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:12:07 by tmaarela          #+#    #+#             */
/*   Updated: 2020/08/11 17:09:56 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			count_n_mbrot(t_mbrot *mb)
{
	mb->n = 0;
	while (mb->n < 50)
	{
		mb->aa = mb->a * mb->a - mb->b * mb->b;
		mb->bb = 2 * mb->a * mb->b;
		mb->a = mb->aa + mb->ca;
		mb->b = mb->bb + mb->cb;
		if (mb->a + mb->b > 16)
			break ;
		mb->n++;
	}
}

static void			count_n_julia(t_julia *j, double ox, double oy)
{
	j->n = 0;
	while (j->n < 50)
	{
		j->aa = j->a * j->a;
		j->bb = j->b * j->b;
		j->twoab = 2 * j->a * j->b;
		j->a = j->aa - j->bb + ox;
		j->b = j->twoab + oy;
		if (j->a + j->b > 16)
			break ;
		j->n++;
	}
}

void				store_image_mandelbrot(t_image *image, int color)
{
	t_mbrot		mb;

	mb.x = 0;
	mb.y = 0;
	while (mb.y < SCREEN_H)
	{
		mb.x = 0;
		while (mb.x < SCREEN_W)
		{
			mb.a = normalize((t_fuck_norm){mb.x, 0, SCREEN_W, image->minx +
			image->offsetx, image->maxx + image->offsetx});
			mb.b = normalize((t_fuck_norm){mb.y, 0, SCREEN_H, image->miny +
			image->offsety, image->maxy + image->offsety});
			mb.ca = mb.a;
			mb.cb = mb.b;
			count_n_mbrot(&mb);
			mb.bright = normalize((t_fuck_norm){mb.n, 0, 50, 1, 0});
			color = calculate_color(mb.bright);
			image->data[(mb.y * image->line) + mb.x] = color;
			mb.x++;
		}
		mb.y++;
	}
}

void				store_image_satan(t_image *image, int color)
{
	t_satan		sn;

	sn.x = 0;
	sn.y = 0;
	while (sn.y < SCREEN_H)
	{
		sn.x = 0;
		while (sn.x < SCREEN_W)
		{
			sn.a = normalize((t_fuck_norm){sn.x, 0, SCREEN_W, image->minx +
			image->offsetx, image->maxx + image->offsetx});
			sn.b = normalize((t_fuck_norm){sn.y, 0, SCREEN_H, image->miny +
			image->offsety, image->maxy + image->offsety});
			sn.ca = sn.a;
			sn.cb = sn.b;
			sn.n = 0;
			loop_satan(&sn);
			sn.bright = normalize((t_fuck_norm){sn.n, 0, 25, 1, 0});
			color = calculate_color(sn.bright);
			image->data[(sn.y * image->line) + sn.x] = color;
			sn.x++;
		}
		sn.y++;
	}
}

void				store_image_julia(t_image *image, int color,
					double ox, double oy)
{
	t_julia		j;

	j.x = 0;
	j.y = 0;
	while (j.y < SCREEN_H)
	{
		j.x = 0;
		while (j.x < SCREEN_W)
		{
			j.a = normalize((t_fuck_norm){j.x, 0, SCREEN_W, image->minx +
			image->offsetx, image->maxx + image->offsetx});
			j.b = normalize((t_fuck_norm){j.y, 0, SCREEN_H, image->miny +
			image->offsety, image->maxy + image->offsety});
			j.ca = j.a;
			j.cb = j.b;
			j.n = 0;
			count_n_julia(&j, ox, oy);
			j.bright = normalize((t_fuck_norm){j.n, 0, 50, 1, 0});
			color = calculate_color(j.bright);
			image->data[(j.y * image->line) + j.x] = color;
			j.x++;
		}
		j.y++;
	}
}
