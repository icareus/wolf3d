/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:19:51 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/30 22:25:14 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <libft.h>

void	mlx_put_pixel_to_image(t_env *e, t_xyz px)
{
	char	*color;
	
	px.z = mlx_get_color_value(e->mlx, arc4random());
	color = (char *)&px.z;
	e->img_start[px.y * e->img_format.x + px.x * e->img_format.z / 8] = color[0];
	e->img_start[px.y * e->img_format.x + px.x * e->img_format.z / 8 + 1] = color[1];
	e->img_start[px.y * e->img_format.x + px.x * e->img_format.z / 8 + 2] = color[2];
	e->img_start[px.y * e->img_format.x + px.x * e->img_format.z / 8 + 3] = color[3];
}

void	rt_compute(t_env *e/*, size_t pixel*/)
{
	t_xyz		pixel;

	pixel.x = 0;
	pixel.y = 0;
	pixel.z = 0;
	ft_putendl("Computing stuff...");
	while (pixel.y < e->win_y)
	{
		while (pixel.x < e->win_x)
		{
			mlx_put_pixel_to_image(e, pixel);
			pixel.x++;
		}
		pixel.x = 0;
		pixel.y++;
	}
}
