/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:28:10 by abarbaro          #+#    #+#             */
/*   Updated: 2014/11/09 23:03:43 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <mlx.h>
#include <libft.h>

static void	set_colors(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

static void	mlx_image_put_pixel(void *mlx, t_img *i, t_coordint p, t_rgb *c)
{
	if (i->e)
	{
		i->d[p.y * i->s + p.x * i->bp / 8] = mlx_get_color_value(mlx, c->r);
		i->d[p.y * i->s + p.x * i->bp / 8 + 1] = mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + p.x * i->bp / 8 + 2] = mlx_get_color_value(mlx, c->b);
	}
	else
	{
		i->d[p.y * i->s + i->bp / 8 * p.x] = mlx_get_color_value(mlx, c->b);
		i->d[p.y * i->s + i->bp / 8 * p.x + 1] = mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + i->bp / 8 * p.x + 2] = mlx_get_color_value(mlx, c->r);
	}
}

void		drawline(int x, t_env *e, t_rgb *c)
{
	t_coordint	p;
	t_rgb		skyfloor;

	p.x = x;
	e->img.d = mlx_get_data_addr(e->img.img, &e->img.bp, &e->img.s, &e->img.e);
	set_colors(&skyfloor, 128, 128, 128);
	p.y = 0;
	while (p.y < e->r.ystart)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
	p.y = e->r.ystart;
	while (p.y < e->r.yend)
	{
		mlx_image_put_pixel(e, &(e->img), p, c);
		p.y++;
	}
	set_colors(&skyfloor, 102, 51, 0);
	p.y = e->r.yend;
	while (p.y < WIN_HEIGH)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
}

void		colors(t_env *e, t_rgb *c)
{
	if (e->player.wallside == 0)
	{
		if (e->player.step.x < 0)
			set_colors(c, 0, 0, 255);
		else
			set_colors(c, 0, 255, 0);
	}
	else
	{
		if (e->player.step.y < 0)
			set_colors(c, 255, 0, 255);
		else
			set_colors(c, 255, 255, 0);
	}
}
